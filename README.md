## Задача:
реализовать контейнер `hash_map`.

### реализуемый класс map:
[`hash_map`](hash_map/hash_map.h) находится в
<pre>$PROJECT_DIR$/hash_map</pre>

### тестирование класса:
тестирование данного класса : [`lab4_hash_map_TEST`](test/priority_queue_TEST.cpp) находится в
<pre> $PROJECT_DIR$/test/test_hash_map.cpp </pre>

Для запуска тестирования данного класса неоходимо выполнить следующее:

#### собрать проект
```bash
$ mkdir build
$ cd build/
$ cmake ..
$ make 
```
#### запустить тестирование
```bash
./test/test_hash_map
```

### banchmark методов класса `insert` и `del_elem`:

banchmark : [`lab4_hash_map_BENCHMARK`](Benchmark/benchmark_hash_map.cpp) находится в
<pre> $PROJECT_DIR$/Benchmark/benchmark_hash_map.cpp </pre>

Для запуска banchmark метода данного класса неоходимо выполнить следующее:

#### собрать проект
```bash
$..."прошлая сборка"
```
#### запустить banchmark
```bash
./Benchmark/lab1_priority_queue_BENCHMARK
```

Как можно заметить добавление элемента и удаление очень сильно приближенно к сложности 

`O(1)`
