zcc +msx -subtype=msxdos -create-app -DAMALLOC msx0.c msx0env.c envsampl.c -o envsampl.com -lm
zcc +msx -subtype=msxdos -create-app -DAMALLOC msx0.c msx0lcd.c lcdsampl.c -o lcdsampl.com
zcc +msx -subtype=msxdos -create-app -DAMALLOC msx0.c msx0lcd.c lcdclock.c -o lcdclock.com
