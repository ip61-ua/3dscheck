FROM devkitpro/devkitarm:latest

RUN apt-get update && apt-get install -y wget unzip build-essential

RUN wget https://github.com/Epicpkmn11/bannertool/releases/download/v1.2.2/bannertool.zip -O bannertool.zip && \
    unzip bannertool.zip -d bannertool_tmp && \
    cp bannertool_tmp/linux-x86_64/bannertool /usr/local/bin/ && \
    chmod +x /usr/local/bin/bannertool && \
    rm -rf bannertool.zip bannertool_tmp

RUN wget https://github.com/3DSGuy/Project_CTR/releases/download/makerom-v0.18.3/makerom-v0.18.3-ubuntu_x86_64.zip -O makerom.zip && \
    unzip makerom.zip -d makerom_tmp && \
    cp makerom_tmp/makerom /usr/local/bin/ && \
    chmod +x /usr/local/bin/makerom && \
    rm -rf makerom.zip makerom_tmp
    
WORKDIR /app