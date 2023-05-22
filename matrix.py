import time
import random
import os
from colorama import Fore, Back, Style

def clear():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def print_slow(text):
    for char in text:
        print(Fore.GREEN + char, end='', flush=True)
        time.sleep(random.uniform(0.1, 0.3))
def print_e_slow(text):
    for char in text:
        print(Fore.GREEN + char, end='', flush=True)
        time.sleep(random.uniform(0.2, 0.5))

def print_fast(text):
    for char in text:
        print(Fore.GREEN + char, end='', flush=True)
        time.sleep(random.uniform(0.05, 0.1))

  

clear()
time.sleep(2)
print_slow("Wake up, Neo...")
time.sleep(random.uniform(4, 7))
clear()
print_e_slow("The Matrix has you...")
time.sleep(random.uniform(4, 7))
clear()
print_fast("Follow the white rabbit.")
time.sleep(random.uniform(4, 7))
clear()
'''
text = "Knock, knock, Neo."
words = text.split()
for word in words:
    print(word, end=' ', flush=True)
    time.sleep(0.2)

'''
print("Knock, knock, Neo.")
time.sleep(10)
clear()