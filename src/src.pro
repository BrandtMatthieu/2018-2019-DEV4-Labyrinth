SOURCES += \
	# console/source/consoleView.cpp \
	# core/controller/source/controllerConsole.cpp \
	core/controller/source/controllerGUI.cpp \
	core/model/source/board.cpp \
	core/model/source/game.cpp \
	core/model/source/objectiveCard.cpp \
	core/model/source/player.cpp \
	core/model/source/position.cpp \
	core/model/source/tile.cpp \
	# core/mainConsole.cpp \
	core/mainGUI.cpp \
	gui/source/askPlayerNameWindow.cpp \
	gui/source/guiView.cpp \
	gui/source/playerInfos.cpp \
	gui/source/welcomeWindow.cpp

HEADERS += \
	# console/include/consoleView.h \
	#  core/controller/include/controllerConsole.h \
	core/controller/include/controllerGUI.h \
	core/model/include/board.h \
	core/model/include/game.h \
	core/model/include/insertSide.h \
	core/model/include/objectiveCard.h \
	core/model/include/player.h \
	core/model/include/position.h \
	core/model/include/tile.h \
	core/utils/include/utils.h \
	gui/include/askPlayerNameWindow.h \
	gui/include/guiView.h \
	gui/include/playerInfos.h \
	gui/include/welcomeWindow.h

TEMPLATE = app
TARGET = Labyrinth

RESOURCES += ./../my.rc

QT += core gui widgets
