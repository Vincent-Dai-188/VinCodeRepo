# coding=utf-8
import os
import sys

def get_args():
    """
    import sys
    if len(sys.argv) == 2:
        targetdir = sys.argv[1]
    else:
        print('Usage: batch-ren_movies_RE.py TARGET-DIR')
        sys.exit(2)
    """
    targetdir = "D:\TDDOWNLOAD\越狱.Prison.Break.S02"
    return targetdir

if __name__ == "__main__":
    targetdir = get_args()
    print("  - Target dir:", targetdir)
    if os.path.exists(targetdir):
        os.chdir(targetdir)
        print()
        
        import re
        ''' RE search somthings like "[66影视www.66ys.tv]" or "[www.66haoys.tv]" '''
        #namePattern = re.compile(r'\[[^\]]+\.(tv)\]', re.IGNORECASE);
        namePattern = re.compile(r'\[66影视www.66ys.cn\]', re.IGNORECASE);
        for fname in os.listdir():
            ret = namePattern.search(fname)
            if ret:
                print('-', fname)
                ''' Substitute
                For example: replace "[www.66haoys.tv]" with "[66tv]" (\g<1> = 'tv')
                #nfname = namePattern.sub(r'[66\g<1>]', fname)
                '''                
                nfname = namePattern.sub('', fname)
                print('  >>', nfname)
                #os.rename(fname, nfname)

        sel = input("Please intput your choice: ")
        if sel != 'Y':
            print("Abort!")
            sys.exit(2)

        print()
        #for fname in os.listdir():
        #    print('+', fname)
    else:
        print("Specified path '%s' does not exist!" % targetdir)
