all: clean

install:
	#if [ "`whoami`" -eq "root" ]; then \
	#	echo "Please install as root"; \
	#fi;
	mkdir -pv /root/bin;
	cp -Rv ./* /root/bin;
	cp -Rv /root/bin/usr/local/share/temporary.mysql/ /usr/local/share/;
clean:
