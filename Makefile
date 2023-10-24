####################################################
#
#	Producer and consumer problem Make file
#	Using G++ coompiler
#
#	Author: Elliott Hager
#	Date: 10/24/2023
#
#
####################################################


consumer: consumer.cpp
	g++ consumer.cpp -pthread -lrt -o consumer


producer: producer.cpp
	g++ producer.cpp -pthread -lrt -o producer


clean:
	rm -f *.o
	rm -f *.out
	rm -f *.gch
	rm -f consumer
	rm -f producer