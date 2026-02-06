import pandas as pd
import matplotlib.pyplot as plt
import sys

def interactive_plotter(file_path):
    try:
        # 1. Load and clean data
        df = pd.read_csv(file_path, sep=None, engine='python', on_bad_lines='skip')
        df.columns = [c.strip().replace('double ', '') for c in df.columns]
        for col in df.columns:
            df[col] = pd.to_numeric(df[col], errors='coerce')
        
        numeric_cols = list(df.select_dtypes(include=['number']).columns)
        
        while True:
            print("\n" + "="*30)
            print(f"FILE: {file_path}")
            print("="*30)
            for i, col in enumerate(numeric_cols):
                print(f" [{i}] {col}")
            
            print("\nOPTIONS:")
            print(" - Enter indices separated by space (e.g., '1 3 4')")
            print(" - Type 'all' to plot everything")
            print(" - Type 'exit' to quit")
            
            choice = input("\nYour selection: ").strip().lower()
            
            if choice == 'exit':
                break
            
            if choice == 'all':
                selected_cols = numeric_cols
            else:
                try:
                    indices = [int(i) for i in choice.split()]
                    selected_cols = [numeric_cols[i] for i in indices if 0 <= i < len(numeric_cols)]
                except:
                    print("Invalid input. Please use numbers or 'all'.")
                    continue

            if not selected_cols:
                print("No signals selected.")
                continue

            # Scaling Option
            scale_choice = input("Scale signals to [0, 1] for comparison? (y/n): ").lower()
            do_scaling = scale_choice == 'y'

            # 2. Plotting
            plt.figure(figsize=(12, 7))
            for col in selected_cols:
                data = df[col]
                label = col
                
                if do_scaling:
                    c_min, c_max = data.min(), data.max()
                    if c_max != c_min:
                        data = (data - c_min) / (c_max - c_min)
                        label = f"{col} (scaled)"
                
                plt.plot(data, label=label)

            plt.title(f"Visualizing: {', '.join(selected_cols)}")
            plt.xlabel("Sample Index")
            plt.ylabel("Normalized Value [0, 1]" if do_scaling else "Raw Value")
            plt.legend(loc='best')
            plt.grid(True, alpha=0.3)
            plt.tight_layout()
            
            print("Close the plot window to return to the menu.")
            plt.show()

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python csv_plotter.py <your_file.csv>")
    else:
        interactive_plotter(sys.argv[1])