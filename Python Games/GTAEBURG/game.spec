# -*- mode: python -*-
a = Analysis(['game.py'],
             pathex=['C:\\Users\\Brian\\Desktop\\Coding\\Games\\GTAEBURG'],
             hiddenimports=[],
             hookspath=None,
             runtime_hooks=None)
pyz = PYZ(a.pure)
exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          name='game.exe',
          debug=False,
          strip=None,
          upx=True,
          console=True )
