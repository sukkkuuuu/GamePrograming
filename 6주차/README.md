
# ์ฌ๋กฏ๋จธ์ ๐๐ฐ๐น๐ฎ
### ์์ ์  ์ด๋ฏธ์ง
<img width="478" alt="image" src="https://user-images.githubusercontent.com/93762014/196649871-7582c117-a97f-44e5-8f64-3bdba76f5f50.png">

### ์์ ์  ๋ฉ์๋๋ค
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

### ๊ฐ์ ํ ์ 

  1. ์ฌ๋กฏ๋จธ์  ํ ๋๋ฐ๋ก ๊ทธ๋ ค์ฃผ๊ธฐ
  2. ๋ ๋ชจ๋ ์์ผ๋ฉด ํ์ฐ ์ถ๋ ฅํ๊ธฐ
  3. ๋ ๋๋ฌด ๋ง์ด ๋ฒ๋ฉด ์ซ๊ฒจ๋๊ธฐ
  4. ๋ด ๋ณด์ ๊ธ์ก๋ณด๋ค ๋ง์ ๊ธ์ก ๋ฐฐํ ๋ชปํ๊ฒํ๊ธฐ
  5. ๊ฒฐ๊ณผ ์ฌ๋กฏ์ ์ฌ์ฉ์๊ฐ ์ ํ  ์ ์๊ฒ ํ๊ธฐ
  6. ๋ฆด ๋ฒํธ๋ณด๋ค ํฐ ์๋ฅผ ์ ํํ๋ฉด ๋ค์ ์๋ ฅํ๋๋ก ๋ง๋ค๊ธฐ


### ์์ ํ ๋ณํ๋๊ฑฐ๋ ์ถ๊ฐ๋ ๋ฉ์๋๋ค
```C
  void draw_check02(int c, int r);
  int game_progress(int money);
  void clear_textall(void);
  void clear_textmoney(void);
  void clear_textbet(void);
  void game_control(char reel[][3], int reel_num[][3], int *money);
```

### ์์ ํ ์ด๋ฏธ์ง
<img width="467" alt="image" src="https://user-images.githubusercontent.com/93762014/196650115-144680c1-a1aa-40ff-8212-0d67dfb43468.png">
