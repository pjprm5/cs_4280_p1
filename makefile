all: P0
clean:
	/bin/rm -f *.o $(TARGET) P0
	/bin/rm -f *.postorder
	/bin/rm -f *.inorder
	/bin/rm -f *.preorder
