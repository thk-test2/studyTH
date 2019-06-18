
### 개발 환경 세팅에 도움되는 것들
- - -
1. git commit 템플릿 설정하기
##### commit 메시지도 일정한 template에 맞춰서 작성해야 한다. template 자동으로 불러오는 방법은 다음을 참고
    - 커밋 템플릿을 다운받는다: commit-template.txt
    - 명령어 실행: git config --global commit.template ~/파일 다운로드 폴더명/commit-template.txt
    - 다음과 같이 본인의 HOME directory 하단의 .gitconfig 파일에 template이 설정되어 있으면,
      template 파일이 제대로 적용된 것

    $ cat ~/.gitconfig
    [user]
	name = xxx
	email = xxx
    [commit]
	template = /home/xxx/파일 다운로드 폴더명/commit-template.txt

2. git change-id 자동으로 생성하기 (gitHub에서는 필요없는 것 같지만 참고로 기록해둠)
##### change-id는 commit 메시지 맨 마지막에 달리는 숫자 코드로써 gerrit 서버에 push 하려면 꼭 있어야 한다.
       commit 메시지 작성시 change-id를 자동으로 넣는 법은 다음을 참고하거나 collab을 찾아보자.
     - 파일 다운로드: commit-msg
     - 명령어 실행: git config --global init.templatedir ~/파일 다운로드 폴더명/
     - 또는, 원격 서버에 push를 했을 때 change-id가 없다고 거부하는데, 이때 나오는 명령어를 쳐도 된다.
       ex) scp -p th.kyong@we.lge.com:hooks/commit-msg ~/파일 다운로드 폴더명/commit-msg

