# minitalk 기본

*UNIX signal을 사용해 IPC 구현...*

- write
<pre> ssize_t wirte(int fd, const void *buf, size_t nbyte);</pre>
> fd : 데이터 전송영역을 나타내는 파일 디스크립터   
> buf : 전송할 데이터를 가지고 있는 버퍼의 포인터   
> nbytes : 전송할 데이터의 바이트 수

- signal
<pre> void *signal(int signum, void (*handler)(int)));</pre>
> signum : 들어오는 시그널 번호   
> handler : signum으로 시그널이 들어왔을때 수행할 핸들러 함수

- sigemptyset
<pre>int sigemptyset(sigset_t *set); </pre>
> set : 시그널 집합   
> 인수로 들어온 시그널 집합에서 모든 시그널을 제거.   
> 성공 시 0, 실패 시 -1 반환

- sigaddset
<pre>int sigaddset(sigset_t *set, int signum);</pre>
> set에 signum 시그널 추가

- sigaction
<pre>int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);</pre>
> signum : 시그널 번호   
> act : 새롭게 지정할 시그널 처리 행동   
> oldact : 이 함수를 호출하기 전에 지정된 행동정보   
> 성공 시 0, 실패 시 -1 반환

- kill
<pre>int kill (pid_t pid, int sig);</pre>
> pid : 시그널을 받을 프로세스 아이디   
> sig : pid로 지정된 프로세스에 보내려는 시그널.   

- getpid
<pre>pit_t getpid(void);</pre>
> 이 함수는 항상 성공하며 해당 프로세스의 ID를 반환.

- malloc

- free

- pause
<pre>int pause(void);</pre>
> 호출 시 시그널을 수신할 때까지 대기상태   
> 항상 -1을 반환하며 errno에는 ERESTARTNOHAND로 설정

- sleep
<pre> void sleep(unsigned long useconds);</pre>
> 지정한 마이크로 초 만큼 대기상태..

- usleep
<pre>
