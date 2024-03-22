#!/bin/sh

## 1. Package 설치

# Repository 인덱스 업데이트
apt-get update

# 패키지 관리자가 https를 이용할 수 있도록 설정
sudo apt-get install -y apt-transport-https

# 다양한 통신 프로토콜을 지원하는 데이터 송,수신 패키지
sudo apt-get install -y curl

# Repository를 추가 및 삭제할 수 있도록 설정하는 패키지
sudo apt-get install -y software-properties-common

# make 설치
sudo apt-get install -y make

# vim 설치
sudo apt-get install -y vim

# ufw 설치
sudo apt-get install -y ufw


## 2. Docker 설치

# Change DNS server to google DNS server
echo "nameserver 8.8.8.8" | sudo tee /etc/resolv.conf > /dev/null

# Repository 인덱스 업데이트
sudo apt-get update

# 도커 패키지 신뢰성 추가
# f - http의 요청 헤더의 Content-Type을 multipart/form-data로 설정
# s - silent로 진행과정 및 오류 생략
# S - SSL 이용
# L - curl의 결과가 Redirection이더라도, 해당 URL로 작업을 이어감
# 파이프 이후의 apt-key는 다운로드 받은 패키지를 인증된 패키지로 인식 시키기 위해 키 리스트에 패키지를 추가
# (apt는 기본적으로 인증된 패키지들을 키 리스트로 관리)
sudo curl -fsSL https://download.docker.com/linux/debian/gpg | sudo apt-key add -

# 도커를 설치할 수 있도록 Repository 추가
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/debian $(lsb_release -cs) stable"

# Repository 인덱스 업데이트
sudo apt-get update

# 도커 설치
sudo apt-get install -y docker-ce docker-ce-cli containerd.io

# 도커 소켓 /var/run/docker.sock 권한 666 설정하여 다른 사용자도 접근할 수 있도록 변경
sudo chmod 666 /var/run/docker.sock

# 도커 컴포즈 설치 (1.29.2 버전)
sudo curl -L "https://github.com/docker/compose/releases/download/1.29.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose

# 도커 컴포즈 실행 권한 부여
sudo chmod +x /usr/local/bin/docker-compose

# 도커 서비스 재시작 시 컨테이너를 종료하지 않도록 설정
sudo su -c "printf "{\n\t\"live-restore\": true\n}" > /etc/docker/docker.json"

# 도커 서비스 재시작
sudo systemctl restart docker


## 3. Sudoer

# 사용자를 sudo 그룹에 추가
sudo usermod -aG sudo kijsong

# 사용자를 root 그룹에 추가
sudo usermod -aG root kijsong

# 사용자를 docker 그룹에 추가
sudo usermod -aG docker kijsong


## 4. mkcert

# Change DNS server to google DNS server
echo "nameserver 8.8.8.8" | sudo tee /etc/resolv.conf > /dev/null

# 리포지토리 목록을 업데이트합니다.
sudo apt-get update

# mkcert를 로드하는 데 도움이 되는 유틸리티를 설치합니다.
sudo apt-get install -y wget curl libnss3-tools

# mkcert 바이너리를 다운로드합니다.
curl -s https://api.github.com/repos/FiloSottile/mkcert/releases/latest | grep browser_download_url | grep linux-amd64 | cut -d '"' -f 4 | wget -qi -

# 다운로드한 파일의 이름을 바꿉니다.
mv mkcert-v*-linux-amd64 mkcert

# 모든 사용자가 파일을 실행할 수 있도록 허용합니다.
chmod a+x mkcert

# 마지막으로 mkcert를 작업 디렉토리로 이동합니다.
sudo mv mkcert /usr/local/bin/

# 로컬 도메인의 별칭(127.0.0.1)을 ${USER}.42.fr로 변경합니다.
sudo sed -i "1 s/localhost/kijsong.42.fr localhost/" /etc/hosts


## 5. Clipboard

# Repository 인덱스 업데이트
sudo apt-get update

# 커널 모듈을 빌드하기 위한 패키지 설치 (uname -r은 커널의 버전을 의미)
sudo apt-get install -y build-essential dkms linux-headers-$(uname -r)

# 광학 이미지를 Mount 하기 위한 디렉토리 생성
sudo mkdir -p /mnt/cdrom

# 광학 이미지를 Mount
sudo mount /dev/cdrom /mnt/cdrom

# Guest Image의 실행 파일을 직접 실행 (nox11은 xterm 화면이 나타나지 않도록 설정)
sudo sh /mnt/cdrom/VBoxLinuxAdditions.run --nox11

# 재부팅
sudo shutdown -r now
