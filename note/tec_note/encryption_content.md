### 混合加密
-----------------------------------------------------------------------------------------

#### 1.RSA混合加密
  - [ ] 简介:
  - [ ] linux下OpenSSL的RSA密钥生成
    - 安装教程:
    ```bash
      1、将下载的压缩包放在根目录，

      2、在文件夹下解压缩，

      命令：tar -xzf  openssl-openssl-1.0.0e.tar.gz

      得到openssl-openssl-1.0.0e文件夹

      3、进入解压的目录：cd openssl-1.0.0e

      4、设定Openssl 安装，( --prefix )参数为欲安装之目录，也就是安装后的档案会出现在该目录下：

      执行命令：./config  --prefix=/usr/local/openssl

      5、执行命令./config  -t

      6.执行make，编译Openssl
    ```
    - 生成密钥和公钥
    ```shell
        ## 生成256位密钥
        openssl genrsa -out private.pem 256
        ## 根据密钥生成公钥
        rsa -in rsa_private.pem -pubout -out rsa_public_key.pem 
    ```
  - [ ] lua-luarsa
  - 使用:
  ```lua
  
  ```
