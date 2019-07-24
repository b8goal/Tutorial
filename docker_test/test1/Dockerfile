FROM ubuntu:16.04
MAINTAINER HyeonSeong Bae<hyeonseong.bae@stradvision.com>

RUN apt-get update -y && apt-get install -y \
  git \
  cmake \
  gcc \
  g++ 

RUN mkdir git

WORKDIR /git

RUN git clone https://github.com/kmansoo/RPiWebUI.Luna 

WORKDIR /git/RPiWebUI.Luna 

RUN git submodule init && git submodule update
RUN mkdir build

WORKDIR /git/RPiWebUI.Luna/build

RUN cmake ..
RUN make -j4

EXPOSE 8000

RUN ./bin/RPiWebUI.Luna ../html/ &

