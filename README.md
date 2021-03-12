# ESP-Controller
ESP controller using lateral vehicle model

1. Later vehicle model

![캡처](https://user-images.githubusercontent.com/79674592/110896165-60318080-833e-11eb-80b8-7b278f626f45.PNG)

![캡처](https://user-images.githubusercontent.com/79674592/110897218-63c60700-8340-11eb-965f-552f9dc20410.PNG)

횡방향 모델을 힘과 토크의 관점에서 해석한 식이다. x축방향은 일정하다고 가정하고 y축방향의 힘은 y축방향의 성분의 힘의 합과 원심력에 의한 힘으로 표현할 수 있다. 토크의 경우 뒷바퀴는 회전하지 않기 때문에 앞바퀴와 다르게 반대로 모멘트가 작용한다.

2. tire model

![캡처](https://user-images.githubusercontent.com/79674592/110897657-2c0b8f00-8341-11eb-8331-d55a0702f6b4.PNG)

tire slip angle은 선회시 side slip이 발생하게 된다. 마찬가지로 앞바퀴의 경우 회전하기 때문에 lfr만큼 앞바퀴에 속도가 더 붙지만 뒷바퀴의 경우 회전하지 않아 회전시 lfr만큼 저항이 발생하게 된다. 

3. X-Y position

![캡처](https://user-images.githubusercontent.com/79674592/110898020-d5528500-8341-11eb-91a5-7509749b6cef.PNG)

4. ESP Controller

- idea : 선회시 모멘트를 추가로 보상하여 언더스티어가 발생하지 않게 하자.

- Esp logic

