## Time Marker Library

A time marker library is a simple tool for time measurements. Just init and mark
in all places where you need.

An example of measurement:
```C++
bool is_simple(size_t number) {
    size_t index = 2;
    do {
        if (number % index == 0) {
            return false;
        }
        ++index;
    } while (index < number);
    return true;
}
mc::timemarker stamp;
for(size_t index = 99999900; index != 100000000; ++index){
    if(is_simple(index) == true){
        std::cout << index << " ";
        stamp.mark();
    }
}
std::cout << std::endl << stamp << std::endl;
```
