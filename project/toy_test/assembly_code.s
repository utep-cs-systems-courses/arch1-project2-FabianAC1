	.arch msp430g2553


	.text
	.global turnOff
turnOff:
	call #led_init
	mov.b #0 , &red_on	;turn off led
	mov.b #0 , &green_on	;turn off led
	call #led_update
	mov #0, r12		;set parametor for buzzer_set_period to 0 too turn off sound
	call #buzzer_set_period

	ret

	
	.text
jt:				;jump table for check state 
	.word option1
	.word option2
	.word option3
	.word option4
	.word default	


	.global check_State
check_State:
	cmp #4, &state 		;comparison so that we dont go out of bounds
	jc default		;jumps to default if barrow flag is not set jmp if state-4 >=0 
	mov &state, r12
	add r12,r12		;multiply state by 2
	mov jt(r12), r0		;move program counter to right place 

option1:
	
	mov.b #1, &switch_state_changed
	mov #1000,r12		;set buzz to 1000
	call #buzzer_set_period
	mov.b #1, &dim1		;this dims red LED
	mov #4, &state
	jmp default

option2:
	
	mov.b #1, &switch_state_changed
	mov &beat, r12		;set buzzer too beat value then add 50 to it
	add #50, &beat
	call #buzzer_set_period
	call #led_init
	call #toggle_red
	mov.b #0, &dim1		
	mov.b #1, &green_on
	call #led_update
	mov #4, &state
	jmp default

option3:

	mov.b #1, &switch_state_changed
	call #turnOff		;calls method to turn everything off
	call #turnOff
	mov.b #0, &dim1
	mov #4, &state
	jmp default

option4:
	 
	mov.b #1, &switch_state_changed
	call #playSong		;calls method to play the office song
	mov.b #0, &dim1
	mov #4, &state
	jmp default

default:
	ret
