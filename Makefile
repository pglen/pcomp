#--------------------------------------------------------------------------
# Makefile for pcomp



all:
	make -C src

git:
	git add .
	git commit -m autocommit
	git push

clean:
	make -C src clean

test:
	make -C src test


