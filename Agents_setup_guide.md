# LangChain Project Setup

A simple setup guide for running a LangChain project using Python, a virtual environment, Jupyter Notebook, and Google Gemini.

## Prerequisites

* Python 3.11 or 3.12
* VS Code
* VS Code Python extension
* VS Code Jupyter extension
* Google Gemini API key

## 1. Clone the Project

```bash
git clone <your-repository-url>
cd <your-project-folder>
```

## 2. Create a Virtual Environment

```bash
python -m venv .venv
```

## 3. Activate the Virtual Environment

### Windows PowerShell

```powershell
.venv\Scripts\activate
```

You should see:

```text
(.venv)
```

before your terminal path.

## 4. Install Dependencies

```bash
pip install -U langchain langchain-google-genai python-dotenv ipykernel
```

If the project has a `requirements.txt` file, use:

```bash
pip install -r requirements.txt
```

## 5. Register the Jupyter Kernel

```bash
python -m ipykernel install --user --name langchain-env --display-name "Python (LangChain)"
```

## 6. Configure the API Key

Create a `.env` file in the project root:

```env
GOOGLE_API_KEY=your_google_gemini_api_key
```

Do not commit `.env` to GitHub.

Add this to `.gitignore`:

```gitignore
.venv/
.env
__pycache__/
.ipynb_checkpoints/
```

## 7. Select the Python Kernel in VS Code

Open the `.ipynb` file.

Select:

```text
Select Kernel
→ Python Environments
→ Python (LangChain)
```

Or select:

```text
.venv\Scripts\python.exe
```

## 8. Test the Environment

Create a notebook cell:

```python
import os

print("Python environment is working")
```

Then test LangChain:

```python
import langchain

print("LangChain:", langchain.__version__)
```

## 9. Initialize Google Gemini

```python
from dotenv import load_dotenv
from langchain_google_genai import ChatGoogleGenerativeAI

load_dotenv()

llm = ChatGoogleGenerativeAI(
    model="gemini-3.5-flash-lite",
    temperature=0
)
```

## 10. Test the LLM

```python
response = llm.invoke("What is LangChain?")

print(response.content)
```

## Temperature

`temperature` controls the randomness of the model's response.

```python
temperature=0
```

is useful for:

* Coding
* SQL
* Technical questions
* Factual responses

Higher values produce more variation and creativity.

## Running the Project

### Jupyter Notebook

Open the `.ipynb` file in VS Code and run cells using:

```text
Shift + Enter
```

To run all cells:

```text
Run All
```

### Python File

If the project uses a Python file such as `main.py`:

```powershell
python main.py
```

## Stop or Restart the Jupyter Kernel

To interrupt execution:

```text
Ctrl + Shift + P
→ Jupyter: Interrupt Kernel
```

To restart:

```text
Ctrl + Shift + P
→ Jupyter: Restart Kernel
```

## Project Structure

```text
langchain-project/
│
├── .venv/
├── .env
├── .gitignore
├── requirements.txt
├── main.py
├── notebook.ipynb
└── README.md
```

## Recommended requirements.txt

```text
langchain
langchain-google-genai
python-dotenv
ipykernel
```

Install everything using:

```powershell
pip install -r requirements.txt
```
