CC = gcc


INC = inc
SRC = src
OBJ = obj
BIN = bin

CFLAGS = -c -g -Wall

LDFLAGS = -o

IFLAGS = -I $(INC)


all: CBMS

CBMS: $(OBJ)/main.o $(OBJ)/cust.o $(OBJ)/driver.o $(OBJ)/trip.o $(OBJ)/common.o
	$(CC) $(LDFLAGS) $(BIN)/CBMS $(OBJ)/main.o $(OBJ)/cust.o $(OBJ)/driver.o $(OBJ)/trip.o $(OBJ)/common.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv main.o $(OBJ)/

$(OBJ)/cust.o: $(SRC)/cust.c
	$(CC) $(CFLAGS) $(SRC)/cust.c $(IFLAGS)
	mv cust.o $(OBJ)/

$(OBJ)/driver.o: $(SRC)/driver.c
	$(CC) $(CFLAGS) $(SRC)/driver.c $(IFLAGS)
	mv driver.o $(OBJ)/

$(OBJ)/trip.o: $(SRC)/trip.c
	$(CC) $(CFLAGS) $(SRC)/trip.c $(IFLAGS)
	mv trip.o $(OBJ)/


$(OBJ)/common.o: $(SRC)/common.c
	$(CC) $(CFLAGS) $(SRC)/common.c $(IFLAGS)
	mv common.o $(OBJ)/


clean:
	rm -f *.out *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	@echo "Cleaning Done!"
