H38465
s 00004/00003/00127
d D 1.18 04/08/05 17:45:06 staelin 19 18
c src/memsize.c
c - if the passed memory size is too big for size_t, then you get invalid
c   memory size requests; in this case just default to 1GB
cC
cHfirewall.staelin.dyndns.org
cK11198
e
s 00000/00020/00130
d D 1.17 04/08/05 12:15:15 staelin 18 17
c src/memsize.c
c - cleanup and remove dead code
cC
cHhpliclu1.hpli.hpl.hp.com
cK10016
e
s 00005/00008/00145
d D 1.16 04/06/13 10:48:28 staelin 17 16
c - fixup sequence of probes so the size grows exponentially with the
c   amount of memory you are checking.  It used to grow linearly by
c   20MB after 200MB of RAM, which took a *long* time on large memory
c   machines.
cC
cHhpliclu2.hpli.hpl.hp.com
cK25992
cZ+03:00
e
s 00001/00001/00152
d D 1.15 02/10/16 16:41:24 staelin 16 15
c memsize.c: fix buglet in command line parsing
cC
cHhpli69.hpli.hpl.hp.com
cK33236
cZ+02:00
e
s 00053/00020/00100
d D 1.14 02/09/29 21:53:51 staelin 15 14
c - Changes for large memory machines to avoid 32-bit integer overflows
c   for size variables.
cC
cHfirewall.staelin.co.il
cK33344
cZ+03:00
e
s 00029/00011/00091
d D 1.13 99/09/02 22:47:55 lm 14 13
c dunno
cC
cHwork.bitmover.com
cK28066
e
s 00004/00004/00098
d D 1.12 98/06/29 22:37:48 lm 13 12
c Redo to compile clean with -Wall.
cK11840
e
s 00002/00002/00100
d D 1.11 97/06/25 10:25:01 lm 12 11
c 64 bit types
cK09868
e
s 00001/00001/00101
d D 1.10 97/06/15 22:38:58 lm 11 10
c lint
cK08508
e
s 00000/00001/00102
d D 1.9 97/06/12 21:30:06 lm 10 9
c new bench.h macros.
cK08246
cZ-07:00
e
s 00004/00003/00099
d D 1.8 96/11/11 03:36:51 lm 9 8
c Auto adjusting changes.
cK09929
e
s 00009/00005/00093
d D 1.7 96/11/08 20:04:25 lm 8 7
c gcc -Wall cleanup.
cK08157
cZ-08:00
e
s 00008/00004/00090
d D 1.6 95/10/25 18:03:42 lm 7 6
c fixing a bug.
cK00920
e
s 00023/00036/00071
d D 1.5 95/10/25 16:06:33 lm 6 5
c *** empty log message ***
cK62740
e
s 00002/00002/00105
d D 1.4 95/08/31 17:17:26 lm 5 4
c remove pagesize dependcy.
cK18481
e
s 00007/00004/00100
d D 1.3 95/08/30 20:41:49 lm 4 3
c *** empty log message ***
cK19335
e
s 00035/00019/00069
d D 1.2 95/08/03 21:05:56 lm 3 2
c take a max count; print the results.
cK14222
cZ-07:00
e
s 00088/00000/00000
d D 1.1 95/02/14 11:03:38 lm 2 1
c Initial revision
cK59731
e
s 00000/00000/00000
d D 1.0 95/02/14 11:03:37 lm 1 0
cBlm@lm.bitmover.com|ChangeSet|20000131225335|47351|--LMBENCH--
cHlm.bitmover.com
cK11395
cPsrc/memsize.c
cR37f652d1bab57b36
cV4
cX0x21
cZ-08:00
e
u
U
f e 4
f x 0x21
t
Figure out memory size.
T
x^�io�F�H��Y��J�mY��(�b�8Y#qS�v�� ɡ40E
<,���{�5CR����D"�7ﾴu���p��z���Վ��ya�з� I�p?T{*6�*�*�J5˖��LU9ӊ!T��@�b�ߺ
[�-2]��*��y�?��V��A�2SU������oL����7�Aԯ���v���nMz{s��#
�?d���Lg��5:;;R���	��=�+��en�*@WU�D����O��Ҕ3$D�)M���5"���A�/��,@=OjQ�%���,M����?�;���y�߃��y���hWiDpc�{�y��^�U��� ;]�Iä��
9��"��}�0��Y�{; }�z�]G����&>*��%x�W��I��au�z=C���:̌`Z'$�����H�&�����x&V}�T��j��S-t�gy���L�~4%hc���Ġ����˗��_~��.`�ٷ����7�Ag	��v�?^���#|�ɿ�)���v�������0�=T���	&z��OIyG�Cf"��AF[�t�w�N�BWLr,��� .v��>�)!\!܂���~Q�	=��^N�tօ�oz�#"�9)b����&����"ClE�n�d�I>p��@��$��Ɵ�Db%bk�{ �Q�8*�h���|�h�P��94~*�6ۙODn��Q�+�A�$
�X��`��~d��}��R�Ǡ��#� o4 �xq��>�G�ߘUe_q���W��st���9�#������D���K�l����[۪�91�!9�z-�s�����~th��U����/�t��yUZ�i
|&Y
U�Mq�,a��LcW����!^���݀+p+���!y���N
��h������5)�����H��V����B1����I(l�r��Q�L��`�HU�BBΪ"�ѡ@a��8��ݨ`"εf:�VL�čssx�2T�����	2.>A�x�Q�@w93�Vt?(4�8���na�޴<^X���Y�!��Υ��Z8'\����qھ�����_ tW�ZJI�Ђ�-��c0�V]|x���oh���L�?G}V�~6N훢��z��e��.,ų�o�t'yA
I���]F#����H�溬�T��,PutR^q��ҢF�=S>>�Nb�c���~�Q�g�tF�W��F���*�/�n����'��*-M��(A�1/�Fh��Ϯt��}'�1݋/l����z�0gY�`è���Zm�� ���NC�d #���ꈛ 膩��>p�w�p�Jn�&���9pMP�f]�eۈ�$R܏��Т@Lpl�aE�A:��CK���Kb�wi�q����g9<� �1��::<iq����^'�j�K2<�ٳ�6��.�Ύ�[�M�M�����pcFj�Y3\ǈ�ȑ}D�mW<������)%��G���mk�H�
�R�hp������T��)��W$Z/`"�NP:���+�6�4' �:�� "�AwüٞƋ�(a�ˡ)� �$�P�{S�$Չ��۸��V�P�7ˑd&j���]�ͼ����(UpJ��:ģ
�/���>!�k%�1��>&2��V-0�n.%}q��,�N��?2Z���j`L"�u�KS�wd�P���4ht�)�3�&`��M������de���zk�	" ���iì���G@\Z���G��-��vX $�dJ�/�XQK�]2�b���A�O�Յ����fP��D�{�7S�y͒�V.��"<�o��'����2[��+v���hp�H�X)�s(D��$���8�X�mG:t$p��zܿ.�?��`�E��Zt���%�\���� rYk��U7*�iy���I�3�	i5��9�g�� �`��8��֋{����	:�'��uo� ���£��P��~��&�� x����¯x*J=/v�0�9K�^�@�c���14(ab�G�0.�(�Ȅ�.CHȇBٟ��#��C�7YV뤸�b1�ަ��0��v5���fL��0�8��u�o��ynYhp@���D+5�k�ҁ�PvE͑��P�zi~�Æ&~�p{��tq��
�MB�q#uR��K�$�In���A���n�k=u���:���ר�2��t�Za�w �T�`u	�f�&��*rw�>��|��h��Q�?{�*�z>��v���-U`�"6��.r�j�Ch�3��`[g���l'��~Өy��>|O��d\t�g�O��U��D���oyO�rc��i�[i8d��M���ZL|��j��ڝ��ԧz��i���b^���z�����8F�V�ƭf�q�y�J�ȷKP׆v3��.,�}�^������$����-cS��u�:,�/�G�O�#60���qa[p�yF�UK;�����y�-��2|% �)M\�ȽW�&�S�/'E:d���(�?��[	,N�5��.�I jMު=�3g�,˝�B&Z���
<ߊ,9@�
Q�ӴVk���㮲'n����F��n�udU:�9���M��I��]��O��[_~�oxs�J�qvpWn��ɥ#��t; ��#w
�1[��P� \|���ݱF�Oۏ�B$���DJ���9����ؗq