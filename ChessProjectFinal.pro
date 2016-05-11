TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    chessboard.cpp \
    coordinate.cpp \
    tile.cpp \
    bishop.cpp \
    king.cpp \
    knight.cpp \
    pawn.cpp \
    piece.cpp \
    queen.cpp \
    rook.cpp \
    chessgame.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    chessboard.h \
    coordinate.h \
    tile.h \
    bishop.h \
    king.h \
    knight.h \
    pawn.h \
    piece.h \
    queen.h \
    rook.h \
    chessgame.h

