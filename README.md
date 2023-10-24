# CpuRunner

CPU 사용량에 따라 사진이 바뀌는 바탕화면 미디어

## Index

목차
> 
1. [Why I Create?](#why-i-create-cpurunner)
2. [Development Environment](#development-environment)
3. [Project Goal](#project-goal)
4. [Not C#?](#not-c)
5. [How To Use](#how-to-use)

## Why I Create CpuRunner?

[RunCat](https://github.com/Kyome22/menubar_runcat)이라는 CPU 사용량에 따라 애니메이션의 속도가 변하는 task에서 볼 수 있는 응용 프로그램이 있다. 해당 프로그램을 색다른 방식으로 구현하고 싶어서 만들게 되었다.

그리고 [RunCat](https://github.com/Kyome22/RunCat_for_windows)이 윈도우 환경에서 지원하는 애니메이션이 매우 한정적인 것이 마음에 들지 않았다.

<details>
<summary>여담</summary>

RunCat은 오픈소스로 공개되어 있다. 하지만 CpuRunner는 배경화면에
크게 배치하는 것을 목표로 두었고, RunCat은 작게 어디서든지 볼 수 있는 것이 목표라는 차이점이 있다.
</details>

## Development Environment

VSCode(Visual Studio Code) 편집기를 활용하였고,
개발 언어는 C/C++.
개발 환경은 WSL2에서 진행하였다.

## Project Goal

프로젝트의 궁극적인 목표는 자기만족이다. 자신이 원하는 사진을 사용할 수 있도록 하는 응용 프로그램을 만드는 것이 최종 목표이다.
그리고 시작 프로그램으로 설정까지 하는 것 역시 목표이다.

## Not C#?

C#을 사용한 개발을 고려하지 않은 것은 아니다.
하지만, C#은 Window라는 환경에서는 특화되어있지만, 다른 환경에서는 .NET Core를 사용해야 할 것으로 판단했기에 C++을 고려하게 되었다.

## How To Use

작성 중..
