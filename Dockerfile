FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    git \
    clangd

# 環境変数
ENV TZ=Asia/Tokyo

# latestのneovimのインストール、通常のapt-getだと古いバージョンしか入らない
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get install -y software-properties-common \
    && add-apt-repository ppa:neovim-ppa/stable \
    && apt-get update \
    && apt-get install neovim -y

# vim-plugのインストール
RUN curl -fLo ~/.local/share/nvim/site/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

# atcoder-cli, ojのインストール
RUN curl -fsSL https://deb.nodesource.com/setup_18.x | bash -
RUN apt install -y nodejs python3-pip
RUN npm install -g atcoder-cli 
RUN pip3 install online-judge-tools

RUN mkdir $(acc config-dir)/cpp && \
bash -c "echo -e '{\"task\":{\n    \"program\": [\"main.cpp\"],\n    \"submit\": \"main.cpp\"\n}}' \
> $(acc config-dir)/cpp/template.json"
COPY main.cpp ./

RUN acc config default-template cpp
RUN mv ./main.cpp $(acc config-dir)/cpp

# oj t で実行できるようにテストのディレクトリ名を変更
RUN acc config default-test-dirname-format test

RUN export CPLUS_INCLUDE_PATH=/workspaces/atcoder-vim/ac-library/ 
RUN mkdir /root/.config/nvim/
COPY ./nvim /root/.config/nvim/

# ログイン
# acc login
# oj login https://atcoder.jp/

# 参考資料
# http://tatamo.81.la/blog/2018/12/07/atcoder-cli-tutorial/
# https://github.com/Tatamo/atcoder-cli#provisioning-templates
# https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md
