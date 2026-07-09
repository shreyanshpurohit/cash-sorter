cash_sorter: cash_sorter.c
	gcc cash_sorter.c -o cash_sorter $(pkg-config --cflags --libs gtk4)

clean:
	rm -f cash_sorter
