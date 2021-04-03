built:
	g++ src/main.cpp src/game.cpp \
	-mwindows \
	-static \
	-DSFML_STATIC \
	-I D:/Libraries/SFML/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/include \
	-L D:/Libraries/SFML/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1\lib \
	-l sfml-graphics-s -l sfml-window-s -l sfml-system-s -l sfml-audio-s \
	-l sfml-audio-s -l sfml-main -l openal32 -l opengl32 -l gdi32 -l ws2_32 \
	-l flac -l ogg -l freetype -l vorbis -l vorbisenc -l vorbisfile -l winmm \
	-o minesweeper.exe
