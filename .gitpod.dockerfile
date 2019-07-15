FROM gitpod/workspace-full

RUN sudo apt-get install nodejs \
    && sudo apt-get install npm \
    && sudo npm install pm2 -g \
    && pm2 install xplorer 