TEST = ../test.out

ifeq ($(shell uname), Linux)
LEAKS =	valgrind -q --leak-check=full --track-origins=yes
else 
LEAKS = leaks
endif		

# UNIT TESTS
main_test:
	@echo "Sans arguments"
	$(TEST)
	@echo "Avec des arguments non-numeriques"
	$(TEST) 3 5 78 "salut" 
	@echo "Avec deux fois le meme nombre"
	$(TEST) 3 5 78 3
	$(TEST) 3 5 78 78
	$(TEST) 3 5 78 1 2 4 6 7 8 546 2516 8787 45 989 8 412
	@echo "Liste valide"
	$(TEST) 3 5 78
	$(TEST) 3 5 78 1 2 4 6 7 8 9 -9 -8 -7 -4 -5 -2 -1
	@echo "Long int"
	$(TEST) 1000000000000
	$(TEST) -2147483648
	$(TEST) -2147483649
	$(TEST) 2147483647
	$(TEST) 2147483648
	@echo "Leaks tests"
	$(LEAKS) $(TEST) 0 1 2
	$(LEAKS) $(TEST) 0 1 2 56646 56 871 5 4 78 -741 -852 -52 8888
