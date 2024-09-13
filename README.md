Example How to overload the QDataStream &operator << and >>. If you have class with private field and you want to get access to it via operator overloading then see unique_ptr_operator_overloading_unique_ptr [example](https://github.com/AndreiCherniaev/unique_ptr_operator_overloading_unique_ptr).
## How to build
```
git clone https://github.com/AndreiCherniaev/overload_QDataStream_example
cd overload_QDataStream_example
mkdir build/
cmake -S src/ -B build/
cmake --build build/ --parallel 
```
