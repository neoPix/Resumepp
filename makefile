all: dir resume

dir:
	mkdir -p obj
	mkdir -p obj/Release
	mkdir -p obj/Release/src

resume: main.o DavidBalan.o Console.o Experience.o Hobby.o PersonnalLink.o Resume.o Skill.o Training.o HtmlResume.o
	g++  -o DavidBalanResume obj/Release/src/Console.o obj/Release/src/DavidBalan.o obj/Release/src/Experience.o obj/Release/src/Hobby.o obj/Release/src/main.o obj/Release/src/PersonnalLink.o obj/Release/src/Resume.o obj/Release/src/HtmlResume.o obj/Release/src/Skill.o obj/Release/src/Training.o  -s

DavidBalan.o: src/DavidBalan.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/DavidBalan.cpp -o obj/Release/src/DavidBalan.o

Console.o: src/Console.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/Console.cpp -o obj/Release/src/Console.o

Experience.o: src/Experience.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/Experience.cpp -o obj/Release/src/Experience.o

Hobby.o: src/Hobby.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/Hobby.cpp -o obj/Release/src/Hobby.o

main.o: src/main.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/main.cpp -o obj/Release/src/main.o

PersonnalLink.o: src/PersonnalLink.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/PersonnalLink.cpp -o obj/Release/src/PersonnalLink.o

Resume.o: src/Resume.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/Resume.cpp -o obj/Release/src/Resume.o

Skill.o: src/Skill.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/Skill.cpp -o obj/Release/src/Skill.o

Training.o: src/Training.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/Training.cpp -o obj/Release/src/Training.o

HtmlResume.o: src/Training.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/HtmlResume.cpp -o obj/Release/src/HtmlResume.o

clean:
	rm -rf obj/Release/src/*.o DavidBalanResume

