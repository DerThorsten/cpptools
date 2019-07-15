#include "pybind11/pybind11.h"

#include "xtensor/xmath.hpp"
#include "xtensor/xarray.hpp"

#define FORCE_IMPORT_ARRAY
#include "xtensor-python/pyarray.hpp"
#include "xtensor-python/pyvectorize.hpp"

#include <iostream>
#include <numeric>
#include <string>
#include <sstream>


// our headers
#include "cpptools/cpptools.hpp"
#include "cpptools/cpptools_config.hpp"

namespace py = pybind11;



namespace cpptools {


    // implementation in def_myclass.cpp
    void def_class(py::module & m);

    // implementation in def_myclass.cpp
    void def_build_config(py::module & m);

    // implementation in def.cpp
    void def_build_config(py::module & m);

}


// Python Module and Docstrings
PYBIND11_MODULE(_cpptools , module)
{
    xt::import_numpy();

    module.doc() = R"pbdoc(
        _cpptools  python bindings

        .. currentmodule:: _cpptools 

        .. autosummary::
           :toctree: _generate

           BuildConfiguration
           MyClass
    )pbdoc";

    cpptools::def_build_config(module);
    cpptools::def_class(module);

    // make version string
    std::stringstream ss;
    ss<<CPPTOOLS_VERSION_MAJOR<<"."
      <<CPPTOOLS_VERSION_MINOR<<"."
      <<CPPTOOLS_VERSION_PATCH;
    module.attr("__version__") = ss.str().c_str();
}