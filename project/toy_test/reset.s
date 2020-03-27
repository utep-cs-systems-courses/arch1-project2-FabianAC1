	.arch msp430g2553
	.extern red_on
	.extern green_on
	.extern buzzer.h

	
	.text
	.global turnOff
	turnOff:call #led_init
	mov.b #0 , &red_on
	mov.b #0 , &green_on
	call #led_update
	mov #0, r12
	call #buzzer_set_period

	ret

	.text
	.global button_state
button_state:
	cmp.b #0, &s1
	jz b2
	mov.b &s1 , &switch_state_down
	mov.b #1, &switch_state_changed
	mov #1000,r12
	call #buzzer_set_period
	mov.b #1, &dim1
b2:
	cmp.b #0, &s2
	jz b3
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
b3:

	cmp.b #0, &s3
	jz b4
	mov.b &s3, &switch_state_down
	mov.b #1, &switch_state_changed
	call #turnOff
	mov.b #0, &dim1

b4:

	cmp.b #0, &s4
	jz end
	mov.b &s4, &switch_state_down
	mov.b #1, &switch_state_changed
	call #playSong
	mov.b #0, &dim1

end:
	ret
	
