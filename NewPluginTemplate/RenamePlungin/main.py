import codecs
import os
import shutil

OldToken = 'MultiPlatformSceneCreatorUpdateConvex'
NewToken = 'MultiPlatformSceneCreatorNaniteTree'


def prepare_output_folder():
    curPath = os.getcwd()
    outputPath = os.path.join(curPath, '..', 'Output')
    templatePath = os.path.join(curPath, '..', 'Template')
    shutil.rmtree(outputPath)
    shutil.copytree(templatePath, outputPath)


def rename_dir_and_file_names():
    curPath = os.getcwd()
    templatePath = os.path.join(curPath, '..', 'Output')
    dirList = []
    fileList = []
    for root, dirs, files in os.walk(templatePath):
        for name in files:
            if OldToken in name:
                fileList.append((root, name))
        for name in dirs:
            if OldToken in name:
                dirList.append((root, name))
    # print(dirList)
    # print(fileList)
    for info in fileList:
        root = info[0]
        name = info[1]
        newName = name.replace(OldToken, NewToken)
        src = os.path.join(root, name)
        des = os.path.join(root, newName)
        os.rename(src, des)
    for info in dirList:
        root = info[0]
        name = info[1]
        newName = name.replace(OldToken, NewToken)
        src = os.path.join(root, name)
        des = os.path.join(root, newName)
        os.rename(src, des)


def rename_class_names():
    curPath = os.getcwd()
    templatePath = os.path.join(curPath, '..', 'Output')
    fileList = []
    for root, dirs, files in os.walk(templatePath):
        for name in files:
            fileList.append(os.path.join(root, name))
    for file in fileList:
        with codecs.open(file, 'r+', 'utf-8') as f:
            content = f.read()
            content = content.replace(OldToken, NewToken)
            f.seek(0)
            f.truncate()
            f.write(content)


if __name__ == '__main__':
    prepare_output_folder()
    rename_dir_and_file_names()
    rename_class_names()
