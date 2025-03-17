import subprocess
import time
from datetime import datetime

def ping_google():
    try:
        # Ping google.com and suppress output
        subprocess.check_output(['ping', '-c', '1', 'google.com'], stderr=subprocess.STDOUT)
        print("Ping successful.")
    except subprocess.CalledProcessError:
        # If ping fails, log the current system time
        with open('ping_fail_log.txt', 'a') as log_file:
            log_file.write(f"Ping failed at {datetime.now()}\n")
        print("Ping failed. Logged the time.")

#Main loop to ping every minute
while True:
    ping_google()
    # Wait for 60 seconds before next ping
    time.sleep(60)
