# Итог

Программа читает из rzhd.db. Если файл не найден, предлагается выбрать его вручную.
На основании данных строится карта ж/д станции. Можно выбрать исходную и конечную точку маршрута
и посторить его на карте станции. Маршрутов можно строить неограниченное количество.
Поиск маршрутов реализован при помощи поиска в ширину. Так же есть вариант поиска в глубину 
- отличие только стэк или очередь. На малых отрезках разницы по времени поиска не замечено.
Программа ведет лог по всем основным своим действиям. Лог находится рядом с исполняемым файлом.


# Курсовой проект
Долго пыталась написать задание с начала, пока не поняла что лучше писать его с конца.

Общая задача:
> Разработать программу, которая по информации из БД строит реберный ориентированный граф - пути жд станции, назовем его картой станции. Реализовать в
озможность нахождения оптимального/всех возможных маршрутов из ребра A в ребро B. С помощью Qt уметь отрисовывать карту графа и найденные пути.

Если сразу учиться отрисовывать граф/части графа, то это позволит сразу видеть прогресс работы и поможет отлаживаться.

### 1. QCustomPlot
http://blog.harrix.org/article/1813

Для отрисовки карты станции отлично подходит библиотека `QCustomPlot`(я не возражаю использования любой другой, если есть такое желание).
1. В [статье](http://blog.harrix.org/article/1813) подробно описано как подключить QCustomPlot и запустить примеры.
Это и есть первая задача.
2. Научиться отрисовывать соединенные точки с заданными координатами


### 2. Изучение БД
1. Изучить базу данных rzhd.db
2. Понять связь таблиц и элементов
3. Подумать над вопросами по БД для меня

### Класс для графа
Разработать класс для работы с ориентированным реберным графов. Каждое ребро графа имеет source(ребро-родитель, входное ребро, для корневых ребер опре
делить как INVALID) и target(дочернее ребро, если дочерних ребер нет или еще не найдены, то INVALID) и уникальный идентификатор ID. Реализовать:
*  возможность добавить ребро
*  возможность удалить ребро
*  поиск ребра по ID
*  поиск дочерних ребер для ребра по ID

### Построение графа - карты жд станции.
Так как мы уже умеет рисовать графики и соединять точки по координатам, то можем сразу видеть результат своей работы. Это самый интересный и самый сло
жный этап.

