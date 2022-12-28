app: app.cpp frames/gamepage.cpp frames/mainframe.cpp frames/startpage.cpp
	g++ app.cpp frames/gamepage.cpp frames/mainframe.cpp frames/startpage.cpp -o app `wx-config --cxxflags --libs`

