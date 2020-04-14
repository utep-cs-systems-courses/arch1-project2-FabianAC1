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
jt:
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
	add r12,r12
	mov jt(r12), r0

option1:
	mov.b &s1 , &switch_state_down
	mov.b #1, &switch_state_changed
	mov #1000,r12
	call #buzzer_set_period
	mov.b #1, &dim1
	mov #4, &state
	jmp default

option2:	
	mov.b &s2, &switch_state_down
	mov.b #1, &switch_state_changed
	mov &beat, r12
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
	mov.b &s3, &switch_state_down
	mov.b #1, &switch_state_changed
	call #turnOff
	mov.b #0, &dim1
	mov #4, &state
	jmp default

option4:	
	mov.b &s4, &switch_state_down
	mov.b #1, &switch_state_changed
	call #playSong
	mov.b #0, &dim1
	mov #4, &state
	jmp default

default:
	ret
