all:
      g++ -std=c++17 main.c -o hello

clean:
      $(RM) hello