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


consumer: ./src/consumer.cpp
	g++ "./src/consumer.cpp" -pthread -lrt -o ./out/consumer


producer: ./src/producer.cpp
	g++ "./src/producer.cpp" -pthread -lrt -o ./out/producer


clean:
	rm -f ./out/consumer
	rm -f ./out/producer