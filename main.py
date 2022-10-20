import os
import shutil
import glob
from typing import List, Optional

import uvicorn
from fastapi import UploadFile, File
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
from fastapi.staticfiles import StaticFiles

app = FastAPI()

app.mount("/static", StaticFiles(directory="static"), name="static")


class MyItem(BaseModel):
    fn: str
    data: str

class MyPath(BaseModel):
    path: str

# origins = [
#     "http://localhost.tiangolo.com",
#     "https://localhost.tiangolo.com",
#     "http://localhost",
#     "http://localhost:8080",
# ]

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


def path_to_dict(path):
    d = {'name': os.path.basename(path)}
    if os.path.isdir(path):
        d['type'] = "directory"
        d['children'] = [path_to_dict(os.path.join(path, x)) for x in os.listdir(path)]
    else:
        d['type'] = "file"
    return d


@app.get("/see-file")
async def see_file():
    # ls = []
    # for x in glob.glob('template/*'):
    #     fn = x.rsplit('\\', 1)[1]
    #     ls.append(fn)
    # return {"files": ls}
    return path_to_dict('template')


# @app.post("/file", status_code=200)
# async def create_upload_files(files: List[UploadFile] = File(...)):
#     for file in files:
#         destination_file_path = "./" + file.filename  # output file path
#         async with aiofiles.open(destination_file_path, 'wb') as out_file:
#             while content := await file.read(1024):  # async read file chunk
#                 await out_file.write(content)  # async write file chunk
#     return {"Result": "OK", "filenames": [file.filename for file in files]}

# @app.post("/file")
# async def file_upload(item: UploadFile = File(...)):
#     with open(f'{item.filename}', 'wb') as buffer:
#         shutil.copyfileobj(item.file, buffer)
#     return {'status': 'True'}


@app.post("/files")
async def create_upload_file(file: List[UploadFile] = File(...)):
    for x in file:
        with open(f'{x.filename}', 'wb') as buffer:
            shutil.copyfileobj(x.file, buffer)
    return {'status': 'True'}


@app.post("/save")
async def save(item: MyItem):
    x = item.fn.rsplit('/', 1)[0]
    os.makedirs(f'.{x}', exist_ok=True)
    with open(f'.{item.fn}', 'w') as f:
        f.write(item.data)
    return {'status': 'True'}


@app.post("/view")
async def view(item: MyPath):
    with open(f'.{item.path}', 'r') as f:
        x = f.read()
    return {'data': x}


if __name__ == "__main__":
    uvicorn.run("main:app", host="127.0.0.1", port=5000, log_level="info", reload=True)
