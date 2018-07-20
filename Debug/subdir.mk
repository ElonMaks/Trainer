################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Button.cpp \
../Chessboard.cpp \
../ChessboardField.cpp \
../ColorsPalette.cpp \
../Game.cpp \
../GameColorsChessboard.cpp \
../GameKeyboardMaster.cpp \
../GameLastHitter.cpp \
../GoodOrBadSign.cpp \
../HighlightFrame.cpp \
../KeyToPress.cpp \
../LogBook.cpp \
../Memocolor.cpp \
../MemocolorOnBoard.cpp \
../MemocolorToDrag.cpp \
../Menu.cpp \
../Program.cpp \
../Scrollbar.cpp \
../Settings.cpp \
../SettingsGameColorsChessboard.cpp \
../SettingsGameKeyboardMaster.cpp \
../SpecialEffects.cpp \
../TaskKeyboard.cpp \
../TaskKeyboardPrototype.cpp \
../TaskKeyboardThumbnail.cpp \
../TaskKeyboardToSelect.cpp \
../main.cpp 

OBJS += \
./Button.o \
./Chessboard.o \
./ChessboardField.o \
./ColorsPalette.o \
./Game.o \
./GameColorsChessboard.o \
./GameKeyboardMaster.o \
./GameLastHitter.o \
./GoodOrBadSign.o \
./HighlightFrame.o \
./KeyToPress.o \
./LogBook.o \
./Memocolor.o \
./MemocolorOnBoard.o \
./MemocolorToDrag.o \
./Menu.o \
./Program.o \
./Scrollbar.o \
./Settings.o \
./SettingsGameColorsChessboard.o \
./SettingsGameKeyboardMaster.o \
./SpecialEffects.o \
./TaskKeyboard.o \
./TaskKeyboardPrototype.o \
./TaskKeyboardThumbnail.o \
./TaskKeyboardToSelect.o \
./main.o 

CPP_DEPS += \
./Button.d \
./Chessboard.d \
./ChessboardField.d \
./ColorsPalette.d \
./Game.d \
./GameColorsChessboard.d \
./GameKeyboardMaster.d \
./GameLastHitter.d \
./GoodOrBadSign.d \
./HighlightFrame.d \
./KeyToPress.d \
./LogBook.d \
./Memocolor.d \
./MemocolorOnBoard.d \
./MemocolorToDrag.d \
./Menu.d \
./Program.d \
./Scrollbar.d \
./Settings.d \
./SettingsGameColorsChessboard.d \
./SettingsGameKeyboardMaster.d \
./SpecialEffects.d \
./TaskKeyboard.d \
./TaskKeyboardPrototype.d \
./TaskKeyboardThumbnail.d \
./TaskKeyboardToSelect.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


