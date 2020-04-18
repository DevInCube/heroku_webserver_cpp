# get and configure an image for building our app
FROM debian:stretch-slim as builder
RUN apt-get update
RUN apt-get install -y --no-install-recommends \
    ca-cacert \
    cmake \
    build-essential \
    libboost-all-dev \
    libboost-system-dev \
    libssl-dev \
    wget \
    zlib1g-dev

# get and build reo7sp/tgbot-cpp
WORKDIR /root
RUN wget https://github.com/reo7sp/tgbot-cpp/archive/v1.2.1.tar.gz
RUN tar zxf v1.2.1.tar.gz
WORKDIR /root/tgbot-cpp-1.2.1/build
RUN cmake -DCMAKE_BUILD_TYPE=Release ..
RUN make -j4 install

# get and build heroku_webserver_cpp
WORKDIR /root
RUN wget https://github.com/DevInCube/heroku_webserver_cpp/archive/v0.1.tar.gz
RUN tar zxf v0.1.tar.gz
WORKDIR /root/heroku_webserver_cpp-0.1/heroku_webserver_cpp/build
RUN cmake -DCMAKE_BUILD_TYPE=Release ..
RUN make -j4 install

# build our app (static linking)
WORKDIR /root/mybot
ADD . /root/mybot
WORKDIR /root/mybot/build
RUN cmake ..
RUN make

# create the final image
FROM debian:stretch-slim
RUN apt-get update
RUN apt-get install -y --no-install-recommends \
    libboost-system-dev \
    libssl-dev
WORKDIR /root
COPY --from=builder /root/mybot/build/mybot.out /root/
RUN ldd ./mybot.out
EXPOSE 3000
CMD ./mybot.out