# ESP-Controller
ESP controller using lateral vehicle model

1. Later vehicle model

<img src="https://github.com/junhyukch7/ESP-Controller/blob/main/image/2.png" width="50%">

![캡처](https://user-images.githubusercontent.com/79674592/110897218-63c60700-8340-11eb-965f-552f9dc20410.PNG)

횡방향 모델을 힘과 횡가속도 관점에서 해석한 방정식이다. x축방향은 일정하다고 가정하고 y축방향의 힘은 y축방향의 성분의 힘의 합과 원심력에 의한 힘으로 표현할 수 있다. 횡가속도의 경우 뒷바퀴는 회전하지 않기 때문에 앞바퀴와 다르게 반대로 모멘트가 작용한다.

2. tire model

<img src="https://github.com/junhyukch7/ESP-Controller/blob/main/image/3.png" width="70%">

tire slip angle은 선회시 side slip이 발생하게 된다. 마찬가지로 앞바퀴의 경우 회전하기 때문에 lfr만큼 앞바퀴에 가속도가 더 붙지만 뒷바퀴의 경우 회전하지 않아 회전시 lfr만큼 저항이 발생하게 된다. (각속도(yaw rate) * 반지름(lf) = 선속도)

<img src="https://github.com/junhyukch7/ESP-Controller/blob/main/image/lateral%20tire%20force.PNG" width="30%">
위에서 구한 tire slip angle을 다음식에 적용하여 tire force를 구하게 된다.

3. X-Y position

![캡처](https://user-images.githubusercontent.com/79674592/110898020-d5528500-8341-11eb-91a5-7509749b6cef.PNG)

4. ESP Controller

- idea : 선회시 횡가속도 방정식에 모멘트를 추가로 보상하여 언더스티어가 발생하지 않게 하자.

- Esp logic

<img src="https://github.com/junhyukch7/ESP-Controller/blob/main/image/formula1.png" width="20%">

<img src="https://github.com/junhyukch7/ESP-Controller/blob/main/image/formula2.png" width="20%">

해당 값에 비례제어를 하기 위해 현재 측정한 yaw rate을 feedback으로 주어 비례제어를 시행한다.

5. Result

![result](https://user-images.githubusercontent.com/79674592/110910244-6a5e7980-8354-11eb-8976-2b254b02a89d.png)
