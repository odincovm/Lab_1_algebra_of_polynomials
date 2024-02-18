# Lab_1_algebra_of_polynomials
Состав группы Одинцов Михаил, Ермилова Дарья, Гнитиенко Кирилл
В рамках данного технического задания предлагается разработать программную систему для выполнения алгебраических операций над полиномами от трех переменных.

Цель проекта: 
создание программной системы, способной обрабатывать, анализировать и выполнять операции над полиномами от трех переменных с учетом их сложной структуры и разнообразия возможных алгебраических операций.

Основные задачи системы:
1. Хранение, организация и управление полиномами от трех переменных.
2. Вычисление значений полиномов в заданных точках.
3. Выполнение алгебраических операций над полиномами, включая умножение, деление,сложение и вычитание.
4. Предоставление возможности работы с несколькими таблицами данных для хранения полиномов с использованием различных структур таблиц.

Предлагаемый план реализации:
1. Структура данных для представления полиномов:
   - Структура данных для хранения одного члена полинома с коэффициентом и степенями по переменным.
   - Структура данных для самого полинома, представленного списком членов.
   - Реализация структур данных для каждого вида таблицы (линейная на массиве, линейная на списке, упорядоченная на массиве, дерево, хэш-таблицы).

2. Реализация операций над отдельным полиномом:
   - Вычисление значения полинома в точке.
   - Умножение полинома на константу.

3. Реализация операций над выражениями полиномов:
   - Сложение, вычитание, умножение на константу, умножение полиномов, деление полиномов.
   - Операции должны выполняться в постфиксной форме.

4. Операции над таблицами:
   - Добавление, удаление полинома из всех таблиц одновременно.
   - Поиск полинома в активной таблице в процессе вычисления выражений.
   - Вывод активной таблицы на экран в формате с двумя столбцами: имя полинома и строковое представление полинома.

5. Общие действия:
   - Разработать интерфейс пользователя для взаимодействия с программой (ввод данных, выбор операций).
   - Реализовать функции для обработки введенных данных и выполнения операций с полиномами.
   - Реализовать проверку на уникальность данных ( на то что данные введенные пользователем уже не находятся в таблице)

Ожидаемые результаты проекта:
- Разработка структур данных для хранения полиномов и их членов.
- Реализация алгоритмов операций над полиномами, включая алгебраические операции и операции с таблицами.
- Создание пользовательского интерфейса для удобного взаимодействия пользователя с программой.
- Проведение тестирования системы для проверки функциональности и корректности выполнения операций.

Общая структура проекта:
тут будут директории

Ограничения:
- Степень монома не превосходит 10.

Используемые инструменты:
- Программа будет написана на языке С++ с использованием Visual Studio
- Для тестирования будут использованы гугл тесты
- Для контроля версий использоваться git
