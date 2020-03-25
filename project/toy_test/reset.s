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
