FROM continuumio/anaconda3:5.0.1

# install sys requirements
RUN apt-get update
RUN apt-get install -y build-essential git

# clone in repo
RUN git clone https://github.com/DerThorsten/cpptools

# update conda
RUN conda update --yes conda

# go into repo
RUN cd cpptools && conda env create -f cpptools-dev-requirements.yml

# activate
RUN echo "source activate cpptools-dev-requirements" > ~/.bash
ENV PATH /opt/conda/envs/cpptools-dev-requirements/bin:$PATH

# activate
#RUN conda activate cpptools-dev-requirements

# make build dir
RUN cd cpptools && mkdir build

# run cmake
RUN  cd cpptools/build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=$(conda info --base)/envs/cpptools-dev-requirements

# build and install project
RUN cd cpptools/build && \
    make -j2 install