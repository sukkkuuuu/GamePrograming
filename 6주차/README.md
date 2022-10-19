
# 슬롯머신🃏🎰🕹🎮
### 수정전 이미지
<img width="478" alt="image" src="https://user-images.githubusercontent.com/93762014/196649871-7582c117-a97f-44e5-8f64-3bdba76f5f50.png">

### 수정전 메소드들
```C
  void display_rule(void);
  void draw_check02(int c, int r);
  void reel_series(int r[][3]);
  void gotoxy(int x, int y);
  int game_progress(int money);
  void display_reel(char rc[][3], int r[][3], int index);
  void clear_text(void);
  void game_control(char reel[][3], int reel_num[][3], int *money);
  int  return_money(int r[], int betting, int *case_n);
```

### 개선한 점

  1. 슬롯머신 표 똑바로 그려주기
  2. 돈 모두 잃으면 파산 출력하기
  3. 돈 너무 많이 벌면 쫓겨나기
  4. 내 보유금액보다 많은 금액 배팅 못하게하기
  5. 결과 슬롯을 사용자가 정할 수 있게 하기
  6. 릴 번호보다 큰 수를 선택하면 다시 입력하도록 만들기


### 수정후 변화되거나 추가된 메소드들
```C
  void draw_check02(int c, int r);
  int game_progress(int money);
  void clear_textall(void);
  void clear_textmoney(void);
  void clear_textbet(void);
  void game_control(char reel[][3], int reel_num[][3], int *money);
```

### 수정후 이미지
<img width="467" alt="image" src="https://user-images.githubusercontent.com/93762014/196650115-144680c1-a1aa-40ff-8212-0d67dfb43468.png">

