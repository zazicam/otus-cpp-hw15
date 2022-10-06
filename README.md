# otus-cpp-hw15

# Задание 15
## Цель задания кластеризация и визуализация результата.

На подготовительном этапе следует подключить библиотеку dlib к своему сборочному окружению. Библиотека находится в пакете libdlib-dev. Для работы потребуется библиотека линейной алгебры, которая в свою очередь находится в пакете libopenblas-dev.

Установка дополнительного репозитория рассматривалась на первом занятии:
echo "deb http://archive.ubuntu.com/ubuntu xenial main universe" | sudo tee -a /etc/apt/sources.list

В качестве основы необходимо взять пример http://dlib.net/kkmeans_ex.cpp.html и собрать из него действующее приложение. 
На основе этого примера необходимо разработать приложение, принимающее на вход строки вида
```
    x1;y1
    x2;y2
    x3;y3
```
где пары xn и yn - это координаты точек в пространстве. 

На выходе приложения должны формироваться строки вида:
```
    x1;y1;cluster1
    x2;y2;cluster2
    x3;y3;cluster3
```
где пары xn и yn - идентичны входным, clustern - номер кластера, к которому относится соответствующая пара.

Подготовить набор входных данных идентичных примеру (учитывая случайность величин один из возможных вариантов).
Подготовить набор входных данных “звездное небо” состоящее из 200 случайных точек координаты которых в диапазоне от -100 до 100 включительно.
Наборы данных должны быть включены в состав пакета.

Приложение должно запускаться командой:
cat kkmeans_ex.txt | kkmeans n
где n - количество кластеров.
Приложить результат визуализации “звездного неба” пузырьковой диаграммой.

* Опционально - предоставить последовательность действий для быстрой визуализации из командной строки (генерация изображения).

## Требования к реализации
Результатом работы должен стать исполняемый файл kkmeans и находиться в пакете kkmeans. Результат работы должен быть опубликован на bintray.

## Проверка
Задание считается выполненным успешно, если после установки пакета и запуска с тестовыми данными удается визуализировать результат пузырьковой диаграммой.

# Результат
Задание показалось мне интересным, поэтому я выполнил как основную (кластеризация) так и бонусную часть задания (программную визуализацию полученных класстеров). В папке data есть 4 примера входных данных с различным распределением. Это сгенерированные специальным образом группы и равномерное двумерное распределение: 
* [Центральный кластер + кольцо вокруг него](https://github.com/zazicam/otus-cpp-hw15/blob/master/data/kkmeans_ex.txt)
  <hr width="1">
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/out-bw.png" width="300">
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/output.png" width="300">
  <hr width="1">
  Здесь количество кластеров было задано равным 3.
* [Равномерное распределение точек](https://github.com/zazicam/otus-cpp-hw15/blob/master/data/kkmeans_ex2.txt)
  <hr width="1">
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/out2-bw.png" width="300"> 
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/output2_n3.png" width="300">
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/output2_n10.png" width="300">
  <hr width="1">
  Результат кластеризации для n1=3 и n2=10 кластеров.
* [3 отдельные группы - вар1](https://github.com/zazicam/otus-cpp-hw15/blob/master/data/kkmeans_ex3.txt)
  <hr width="1">
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/out3-bw.png" width="300">
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/output3.png" width="300">
  <hr width="1">
* [3 отдельные группы - вар2](https://github.com/zazicam/otus-cpp-hw15/blob/master/data/kkmeans_ex4.txt)
  <hr width="1">
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/out4-bw.png" width="300">
  <img src="https://github.com/zazicam/otus-cpp-hw15/blob/master/data/output4.png" width="300">
  <hr width="1">
Расположение точек в этих примерах показано на рисунках.



