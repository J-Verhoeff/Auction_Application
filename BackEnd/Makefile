JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	src/User.java \
	src/Item.java \
	src/Parse.java \
	src.Main.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class src/*.class
