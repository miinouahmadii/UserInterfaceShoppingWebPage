all : a.out

a.out : main.o user.o handle_input.o market.o product.o car.o offer.o comment.o cart.o
	g++ main.o user.o handle_input.o market.o product.o car.o offer.o comment.o cart.o -o a.out

main.o: main.cpp market.h
	g++ --std=c++11 -c main.cpp -o main.o

user.o : user.cpp user.h offer.h
	g++ --std=c++11 -c user.cpp -o user.o

market.o : market.cpp market.h handle_input.h car.h
	g++ --std=c++11 -c market.cpp -o market.o

handle_input.o : handle_input.cpp handle_input.h 
	g++ --std=c++11 -c handle_input.cpp -o handle_input.o

product.o : product.cpp product.h 
	g++ --std=c++11 -c product.cpp -o product.o

car.o : car.cpp car.h product.h
	g++ --std=c++11 -c car.cpp -o car.o

tv.o : tv.cpp tvr.h product.h
	g++ --std=c++11 -c tv.cpp -o tv.o

mobile.o : mobile.cpp mobile.h product.h
	g++ --std=c++11 -c mobile.cpp -o mobile.o

offer.o : offer.cpp offer.h 
	g++ --std=c++11 -c offer.cpp -o offer.o

comment.o : comment.cpp comment.h 
	g++ --std=c++11 -c comment.cpp -o comment.o

cart.o : cart.cpp cart.h 
	g++ --std=c++11 -c cart.cpp -o cart.o

.PHONY: clean

clean:
	rm *.o
	rm *.out