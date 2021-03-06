# 42_minitallk

*요약 : 이 프로젝트의 목적은 UNIX signal을 사용해 작은 데이터를 교환하는 프로그램을 작성하는 것입니다.

## 들어가며

(Z)-3-hexen-1-ol과 leaf alcohol로 알려진 cis-3-Hexen-1-ol은 갓 자른 푸른 잔디와 잎의 강렬한 잔디 녹색 냄새가 나는 무색 유성 액체입니다.    
대부분의 식물에게 아주 소량으로 생산되며 많은 포식 곤충들에게 매력적으로 작용합니다.   
cis-3-Hexen-1-ol 은 과일과 야채의 맛, 향수에 사용되는 아주 중요한 아로마 화합물입니다.   
연간 30톤 생산됩니다.

## 공통 구조
- 프로젝트는 반드시 Norm과 일치되어야 합니다. 만약 보너스파일과 함수가 있다면, 그들도 norm check에 포함되며 내부에 에러가 있다면 0점을 받게 됩니다.
- 함수는 정의되지 않은 행동을 제외하고 종료되지 않아야 합니다. (segmentation fault, bus error, double free 등등..) 평가동안 이것이 발생한다면, 당신의 프로젝트는 기능하지 않는 것으로 간주되며 0점을 받게 됩니다.
- 힙에 할당된 모든 메모리 공간은 필요에 따라 모두 알맞게 해제되어야 합니다. leak은 용납할 수 없습니다.
- 과제가 요구한다면, 당신은 반드시 -Wall, -Wextra, -Werror 플래그와 함께 소스파일을 컴파일 하는 `Makefile`을 제출해야 합니다. Makefile은 relink되어선 안됩니다.
- 당신의 `Makefile`은 최소한 `$(NAME), all, clean, fclean, re` 규칙을 포함해야 합니다.
- 보너스를 받기 위한다면, 반드시 `bonus`규칙을 `Makefile`에 포함시켜야 합니다. `bonus`규칙엔 모든 다양한 헤더와 라이브러리들이나 메인파트에서 금지된 함수들이 추가될 것입니다. 보너스는 반드시 다른 파일이여야 합니다. `_bonus.{c/h}`. 필수파트와 보너스파트의 평가는 분리되어 있습니다.
- 당신의 프로젝트가 `libft`를 사용하는 것을 허락한다면, 소스를 카피해서 `Makefile`에 `libft`폴더와 `Makefile`을 넣어야 합니다. 프로젝트는 `Makefile`로 컴파일 되어야 합니다.
- 우리는 당신의 프로젝트가 제출하지않고 채점되어지지 않더라도 테스트프로그램을 만들 것을 권장합니다. 조금 더 쉽게 테스트하고 평가받을 수 있게 될 겁니다. 디펜스동안 테스트 결과들은 유용하다는 것을 발견할겁니다. 디펜스동안 필요하다면, 동료에게 테스트를 사용하는 것은 자유입니다.
- 프로젝트를 할당된 깃 레포지토리에 제출하세요. 깃 레포지토리에 있는 것만 채점됩니다. 만약 Deepthought가 채점하지 않는다면, 동료평가 이후에 채점될 겁니다. Deepthought가 채점하는 동안 에러가 발생한다면 평가는 중지됩니다.
- 실행파일의 이름은 반드시 `client`와 `server`로 해야합니다.
- 당신은 예민하게 에러를 관리해야 합니다. 예상치 못하게 프로그램이 꺼지는 방법이 없어야 합니다.(segmentation fault, bus error, double free 등).
- 메모리 leak을 가지고 있으면 안됩니다.
- 필수파트에서 허용된 함수는 아래와 같습니다.
  - write
  - signal
  - sigemptyset
  - stgaddset
  - sigaction
  - kill
  - getpid
  - malloc
  - free
  - pause
  - sleep
  - usleep
  - exit


## 필수 파트
- 클라이언트와 서버가 통신하는 프로그램을 만들어야 합니다.
- 서버가 처음으로 실행되어야 합니다. 후에 실행되었을 때 반드시 PID를 화면에 표시해야 합니다.
- 클라이언트는 다음을 파라미터로 받게 됩니다.
  * 서버의 PID
  * 보내질 문자열
- 클라이언트는 파라미터로 들어온 문자열을 서버로 통신해야 합니다. 서버가 문자열을 받았다면, 반드시 화면에 표시해야 합니다.
- 당신의 프로그램 간 통신은 '반드시' `UNIX` 신호를 이용해야 합니다.
- 서버는 문자열을 개빠르게 보여줄 수 있어야 합니다. 우리가 말하는 '빠르게'는 당신이 생각하는 '너무 느리다'는 아마 진짜 느릴거기 때문에 말하는 겁니다.(힌트 : 100개의 문자를 1초에 보내는건 엄청나다;;)
- 당신의 서버는 재시작할 필요 없이 여러 클라이언트로 부터 문자열을 받을 수 있어야 합니다.
- 오직 두개의 신호를 사용 할 수 있습니다. `SIGUSR1`과 `SIGUSR2`.

## 보너스 파트
- 작은 확인 시스템을 만드세용...
- 유니코드 문자를 지원하세용~

## 제출과 동료평가

깃 레포지토리에 제출하세요. 오직 깃 레포지토리에 있어야 평가됩니다.
