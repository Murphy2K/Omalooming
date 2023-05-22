import tkinter as tk

# Create a new Tkinter window
root = tk.Tk()

# Set the title of the window to "Hello World"
root.title("Hello World")

# Set the size of the window to 500x500 pixels
root.geometry("150x500")

# Create a new button widget with the text "Submit" that will call the submit() function when clicked
submit_button = tk.Button(root, text="Submit", command=submit)

# Use the place() method to position the button at coordinates (100, 100)
submit_button.place(x=100, y=100)

# Create a new button widget with the text "Exit" that will call the exit_program() function when clicked
exit_button = tk.Button(root, text="Exit", command=exit_program)

# Use the place() method to position the button at coordinates (200, 200)
exit_button.place(x=200, y=200)

# Start running the Tkinter event loop
root.mainloop()

  