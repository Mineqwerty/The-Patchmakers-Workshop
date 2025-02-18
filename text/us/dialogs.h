// Parameters: dialog enum ID, (unused), lines per box, left offset, width

#include "include/dialog_ids.h"

#ifdef VERSION_EU
#define COMRADES "friends"
#define PLASTERED "splattered"
#define SCAM_ME "cheat!\n"
#define SCRAM "get lost"
#else
#define COMRADES "comrades"
#define PLASTERED "plastered"
#define SCAM_ME "scam\nME. "
#define SCRAM "scram--"
#endif

DEFINE_DIALOG(DIALOG_ROSEDRIFT_INTRO, 1, 3, 30, 200, _("\
Hi there! You seem to be new around here.\n\
Oh don't look so tense, we aren't like our\n\
Spindrift cousins at all!\n\
I'm a Rosedrift! Sort of a relative to\n\
Spindrifts. We live here in these\n\
rugged, thorny cliffs. \n\
Hey, here's a bit of friendly advice:\n\
Watch out from above. The Ptooies that live\n\
here aren't so friendly towards new faces."))

DEFINE_DIALOG(DIALOG_ROSEDRIFT_GOOMBAS, 1, 3, 95, 200, _("\
The local goombas have been acting strangely\n\
for a decent while now.\n\
Look at that blank stare, are they ok?"))

DEFINE_DIALOG(DIALOG_ROSEDRIFT_BOUNCY, 1, 4, 95, 200, _("\
The flowers that grow \n\
here are all pretty\n\
bouncy on top.\n\
\n\
What are you looking\n\
at me for?\n\
\n\
\n\
...yes that includes\n\
us Rosedrifts too.\n\
But we wouldn't let\n\
you bounce on us."))

DEFINE_DIALOG(DIALOG_SEWNIA_OPTIONS, 1, 6, 95, 200, _("\
@7F60B4FFWhat can I help you with, Mario?\n\
\n\
     @FFFFFFFFJust wanted to talk\n\
     About this stage\n\
     Toggle following"))

DEFINE_DIALOG(DIALOG_JOURNAL_TTC, 0b100, 3, 95, 200, _("\
@FEFEFEFFMy first attempt at portal technology\n\
had led me to a pleasant cliffside full of\n\
plant life, bustling with energy.\n\
@FEFEFEFFA plant-like race resides here. They were quite\n\
friendly greeting me, and to think I was\n\
nervous to bring Sewnia with me...\n\
@FEFEFEFFApparently, they have a related cousin\n\
species known as a Spindrift in a far-off\n\
land called the Mushroom Kingdom.\n\
@FEFEFEFFRegardless, I must remain cautious. Even though\n\
I doubt I'll find anything of use here, there are\n\
rumors of a large burrowing creature beneath...\n\
@FEFEFEFFIf it were to attack me, I wonder how I\n\
could defend myself..."))

DEFINE_DIALOG(DIALOG_JOURNAL_RDR, 0b100, 3, 30, 200, _("\
@FEFEFEFFMy portals are still quite aimless...\n\
Now I have ended up in a rural roadside, one\n\
that has seemingly endless rain.\n\
@FEFEFEFFI'm unsure at the moment if my portals are\n\
connecting to far-away places in this world,\n\
or if they are traveling to other worlds entirely.\n\
@FEFEFEFFStill, like the last place I traveled to,\n\
this place is brimming with life and nature.\n\
A mute mud-people even reside here.\n\
@FEFEFEFFI won't find what I'm looking for here, but\n\
perhaps if I explore, I could find out\n\
why the portal led to here in the first place..."))

DEFINE_DIALOG(DIALOG_JOURNAL_STC, 0b100, 3, 30, 200, _("\
@FEFEFEFFImagine my shock to see a vast, open sky when\n\
I emerged from this portal!\n\
Not only that, but under my feet were buildings!\n\
@FEFEFEFFThis is no ordinary city. It is an ancient one.\n\
And yet, the buildings pierce the clouds...\n\
This is a place of secret technology.\n\
@FEFEFEFFI could certainly find something interesting here...\n\
But will it be what I desire to find?\n\
Likely not. But I am patient.\n\
@FEFEFEFFAn interesting development is that I believe I\n\
know why the portal led here... While opening it,\n\
I was thinking much of the past.\n\
@FEFEFEFFWith my head in the clouds like that, it's no\n\
wonder I ended up here... But now, I must\n\
imagine a place that has secrets of life.\n\
@FEFEFEFFMy first thought is to visit a place\n\
past life itself... an afterlife of sorts?\n\
Perhaps there I could gain knowledge..."))

DEFINE_DIALOG(DIALOG_JOURNAL_GSS, 0b100, 3, 30, 200, _("\
@FEFEFEFFI have been wounded...\n\
I was a fool for coming here.\n\
Even with a patch of divinity, I lost.\n\
@FEFEFEFFWhen I entered the palace in the sky,\n\
a strikingly beautiful goddess met me.\n\
I was hesitant when the room smelled of burning flesh...\n\
@FEFEFEFFBut despite my fear, I asked her to reveal the\n\
secrets of fabricating life to me.\n\
And she laughed.\n\
@FEFEFEFFI then realized that the scent of burning was from\n\
her. The gold that adorned her realm was a blood curse,\n\
meant to keep her suffering and weak.\n\
@FEFEFEFFShe attacked me with vengeance, to kill.\n\
I had no choice but to escape after I could\n\
not defend myself enough.\n\
@FEFEFEFFSewnia will be terrified to see me like this...\n\
I doubt normal medicine will heal these burns.\n\
Perhaps... a portal to a healing place will help."))

DEFINE_DIALOG(DIALOG_JOURNAL_SS, 0b100, 3, 30, 200, _("\
@FEFEFEFFAs I lay in these saline waters, my burns healing,\n\
I can't help but reconsider my journey.\n\
Sewnia was a miracle. Maybe I'm a fool for this...\n\
@FEFEFEFFWould I be satisfied giving up now?\n\
...No. I wouldn't. I want to know how she was created.\n\
She seemed so excited at the thought of a sister...\n\
@FEFEFEFFStill, I must return to her.\n\
I can't lose my life over this.\n\
I must be more careful from now on.\n\
@FEFEFEFFPerhaps my good friend has some\n\
secrets within his library that\n\
may help..."))

DEFINE_DIALOG(DIALOG_JOURNAL_CLC, 0b100, 3, 30, 200, _("\
@FEFEFEFFAs I understand it, life exists in\n\
different states, whether that may be\n\
the life I possess, or the ones of the ghosts here.\n\
@FEFEFEFFTo the dismay of the Master and Mistress,\n\
I have asked a few of the spirits here how\n\
they came to be... apparently it is a sensitive topic.\n\
@FEFEFEFFAsking to experiment on them was a terrible\n\
thing to do of me. Even though they are ghosts,\n\
they should still be treated as living creatures.\n\
@FEFEFEFFHow mad would I have to be to harm beings such as them?\n\
The Master and Mistress are good friends of mine.\n\
I would never do something to tarnish that relationship.\n\
@FEFEFEFFStill... it appears I am at another dead-end.\n\
I wonder, just what places will I have to visit\n\
to get any answers at all?"))

DEFINE_DIALOG(DIALOG_JOURNAL_HVH, 0b100, 3, 30, 200, _("\
@FEFEFEFFNever in a thousand years did I think I would\n\
travel here. This place is... fictional. It must be.\n\
I was thinking of a fictional place with the portal.\n\
@FEFEFEFFAnd yet, if I am here, am I fictional?\n\
Of course not. And yet, the book was not written of\n\
reality, either. So then, have I made this real?\n\
@FEFEFEFFI doubt it. Even if my wishes gave rise to this\n\
place, I could never hope to consider myself its creator.\n\
A fiction that resides in many minds is close to real, anyways.\n\
@FEFEFEFFHa...\n\
My head is spinning just thinking about it.\n\
I'm sure Sewnia would love to hear about this.\n\
@FEFEFEFFI wonder, just how much does this place\n\
obey reality? Perhaps then I can determine its\n\
status."))

DEFINE_DIALOG(DIALOG_JOURNAL_VTW, 0b100, 3, 30, 200, _("\
@FEFEFEFFIn fiction I've walked, and in dreams I now stand.\n\
A place that I warped to, yet not by my hand.\n\
This dream is not mine, 'tis not my own land.\n\
@FEFEFEFFWhy is it that a dream realm such as this\n\
does not fulfill mine? Perhaps it is\n\
a selfish notion, after all.\n\
@FEFEFEFFI feel this place would be a good time\n\
to end my journey. The soothing scent of flowers\n\
relaxes my worries like nothing else.\n\
@FEFEFEFFI can imagine it now...\n\
Returning to the workshop, going back to small\n\
projects, raising Sewnia ever more.\n\
@FEFEFEFFI'm feeling nostalgic just imagining it.\n\
But... I know I'll never forgive myself for giving up.\n\
I... promised Sewnia, after all.\n\
@FEFEFEFF...\n\
\n\
\n\
@FEFEFEFFOne more try. Just one more.\n\
Next time, I'll warp somewhere that\n\
WILL give me this knowledge."))

DEFINE_DIALOG(DIALOG_012, 1, 4, 30, 200, _("\
SS"))

DEFINE_DIALOG(DIALOG_HUNDRED_COINS, 1, 5, 30, 200, _("\
You obtained the 100 coin star!\n\
With the search over, Mario breathes\n\
a relieved sigh and continues on!"))

DEFINE_DIALOG(DIALOG_SECRET_STAR, 1, 3, 30, 200, _("\
You found a secret star!\n\
With another mystery uncovered,\n\
it's time to keep searching!"))

DEFINE_DIALOG(DIALOG_OBELISK, 1, 4, 30, 200, _("\
Activate the Obelisk? \n\
//Yes    //No      "))

DEFINE_DIALOG(DIALOG_JOURNAL_TFP, 1, 3, 30, 200, _("\
@FEFEFEFFI've made a horrible mistake.\n\
I'm lost. Terribly lost.\n\
I know not how long it has been.\n\
@FEFEFEFFEvery attempt I've made at opening\n\
a portal back home has led me to an\n\
even more twisted, confusing space.\n\
@FEFEFEFFI'm sorry. I'm so sorry, Sewnia.\n\
I should have listened to you.\n\
I should have stayed.\n\
@FEFEFEFFI feel my mind slipping from me.\n\
It's terrifying.\n\
I'm scared.\n\
@FEFEFEFFWriting like this has always kept me sane when alone,\n\
but this time I fear it is not enough.\n\
Would I truly exist if my mind was not my own?\n\
@FEFEFEFF...I need to escape here. Before it is too late.\n\
Before I emerge a different man."))

DEFINE_DIALOG(DIALOG_JOURNAL_EA, 1, 3, 30, 200, _("\
@5C5C5CFFThe pages of the journal are all torn apart...\n\
The only parts that can be made out contain words\n\
of spite and hatred, with little coherence..."))

DEFINE_DIALOG(DIALOG_JOURNAL_CORR, 1, 4, 30, 200, _("\
@FEFEFEFFThe snow helps me feel as though I am in my\n\
own flesh again... It's a nice feeling.\n\
A nice feeling. Yes, it is.\n\
@FEFEFEFFI used to love writing these, did I not?\n\
I must have, considering I always have a journal\n\
on me. My memory of the last few I wrote is fuzzy.\n\
@FEFEFEFFWhy... why did I come here again?\n\
My goal... a sister for Sewnia, right.\n\
Why... did I think it would be here?\n\
@FEFEFEFFIt's cold. Haha...\n\
I met a man here. He was moving away from this\n\
section of the city to meet his family again.\n\
@FEFEFEFFIt's quite sad how much hope remains here.\n\
The snow is never going to stop, the buildings will never\n\
stay upright for long, so why bother?\n\
@FEFEFEFFFamily... I want to see my family.\n\
Why am I not with Sewnia? Did I even...\n\
tell her I was leaving?\n\
@FEFEFEFFI'm not well. If I could just...\n\
If I could finally find the secrets for life,\n\
my entire life would be fixed. Healed.\n\
@FEFEFEFFThe snow feels nice. I hope that,\n\
once I find the secrets to life,\n\
things can just go back to normal."))

DEFINE_DIALOG(DIALOG_JOURNAL_TS, 1, 3, 30, 200, _("\
@FEFEFEFFThey're here. The secrets are here.\n\
I know not if this realm appeared from my pleas,\n\
or if it always existed, but life itself is here.\n\
@FEFEFEFFMy mind is refocused with determination.\n\
One that tells me things can still return to normal.\n\
I can still fix everything, Sewnia.\n\
@FEFEFEFFI'll return with the secrets. I'll make you\n\
a sister. And then, we can live a happy life\n\
as a family. I'll feel complete, accomplished.\n\
@FEFEFEFFThings cannot be fixed without me returning\n\
with the secrets of life. So I must.\n\
I will not return empty-handed."))

DEFINE_DIALOG(DIALOG_020, 1, 6, 95, 150, _("\
C11"))

DEFINE_DIALOG(DIALOG_021, 1, 5, 95, 200, _("\
C12"))

DEFINE_DIALOG(DIALOG_MEET_SEWNIA, 1, 3, 95, 200, _("\
@7F60B4FFH... Hi...\n\
\n\
\n\
@7F60B4FFSorry... I didn't mean to scare you like that...\n\
I got a little scared too, so it's okay...\n\
\n\
@7F60B4FFOh... You look like you don't know what's going on...\n\
Right, of course you wouldn't. Silly me...\n\
I'll try to tell you as much as I know.\n\
@7F60B4FFSee, up until just now, you weren't exactly... alive?\n\
You were attacked and captured by a man known as\n\
The Patchmaker, who transformed you into a lifeless doll.\n\
@7F60B4FFHe used a forbidden craft technique called\n\
The Thread of Life to steal your soul away in a thread,\n\
trapping it within an object. That letter on your cap.\n\
@7F60B4FFHe then took you here, to this workshop...\n\
And... Um... That's not all...\n\
He got your friends too..."))

DEFINE_DIALOG(DIALOG_MEET_SEWNIA_2, 1, 3, 95, 200, _("\
@7F60B4FFDon't worry, we can fix this! It's not too late!\n\
Ah... But it might be tough with what we have...\n\
The Patchmaker probably has their threads...\n\
@7F60B4FFThere is another issue too.\n\
Um... Just follow me...\n\
...?\n\
@7F60B4FFWhat did you say? My name?\n\
Oh my gosh! I completely forgot!\n\
My name is Sewnia.\n\
@7F60B4FFAnd your name is?\n\
...\n\
Mario huh? Nice to meet you Mario!\n\
@7F60B4FFUh... Right! Follow me!\n\
...\n\
Oh, oops! Follow me, Mario!"))

DEFINE_DIALOG(DIALOG_MEET_SEWNIA_3, 1, 5, 95, 200, _("\
@7F60B4FFSo... the rest of the workshop is beyond here.\n\
It's actually a really big building complex.\n\
The Patchmaker had some plans before, uh...\n\
...Anyways, the problem.\n\
\n\
@7F60B4FFHe kind of um... Locked me in here.\n\
With magic. No matter how you try, it won't open.\n\
This is the only way forward, too...\n\
I'm sorry, but we're stuck here until I think\n\
of a way to get past it...\n\
@7F60B4FF...Huh? You've opened sealed doors before?\n\
You make it sound really easy!\n\
All we need is something called star power?\n\
And it can be found anywhere? Lucky!\n\
\n\
@7F60B4FFLeaving the workshop isn't a good idea, but\n\
I think I know how to help! Follow me!"))

DEFINE_DIALOG(DIALOG_NEED_10_STARS, 1, 4, 95, 200, _("\
@FEFEFEFFIt seems the power of\n\
10 stars can break the\n\
seal. You need [%] more\n\
stars."))

DEFINE_DIALOG(DIALOG_NEED_35_STARS, 1, 4, 95, 200, _("\
@FEFEFEFFIt seems the power of\n\
35 stars can break the\n\
seal. You need [%] more\n\
stars."))

DEFINE_DIALOG(DIALOG_CLC_DOOR_LOCKED, 1, 2, 95, 200, _("\
@FEFEFEFF...It seems that the door is locked\n\
from the other side."))

DEFINE_DIALOG(DIALOG_CLC_MASTER_DOOR, 1, 4, 95, 200, _("\
@FEFEFEFF...It's best to leave this door\n\
alone until you are invited to the\n\
Master's chamber..."))

DEFINE_DIALOG(DIALOG_029, 1, 5, 95, 200, _("\
To open the door that\n\
leads to the 『endless』\n\
stairs, you need 70\n\
Stars.\n\
Bwa ha ha!"))

DEFINE_DIALOG(DIALOG_MEET_SEWNIA_4, 1, 3, 30, 200, _("\
@7F60B4FFBelieve it or not, this pot is a portal!\n\
It can bring you to a place far away,\n\
and there are a bunch more like it in here!\n\
@7F60B4FFThe Patchmaker went on a journey a long time ago,\n\
and he made these portals to explore the reaches\n\
of the world!\n\
@7F60B4FFYou might find some of that star power in here!\n\
But, um... It might be dangerous.\n\
When the Patchmaker went in, he had...\n\
@7F60B4FFThat's right! Mario, inside each of these worlds\n\
should be a copy of the patches he made!\n\
He hid them for the case of an emergency.\n\
@7F60B4FFThey aren't ordinary patches, they have\n\
strong magic that can give you new\n\
abilities!\n\
@7F60B4FFFor this world, he made the stone patch\n\
to help him wave aside thorny bushes.\n\
If you find it, you should try it out!\n\
@7F60B4FFKeep an eye out for the patches while you\n\
look for stars, they're probably super\n\
helpful!\n\
@7F60B4FFGood luck, Mario...\n\
I'll be waiting here for you!\n\
If you need help, just ask me!"))

DEFINE_DIALOG(DIALOG_031, 1, 5, 30, 200, _("\
No way! You beat me...\n\
again!! And I just spent\n\
my entire savings on\n\
these new Koopa\n\
Mach 1 Sprint shoes!\n\
Here, I guess I have to\n\
hand over this Star to\n\
the winner of the race.\n\
Congrats, Mario!"))

DEFINE_DIALOG(DIALOG_PHANTASMAID_NERVOUS, 1, 3, 30, 200, _("\
A... A guest! H-How did you...?\n\
\n\
\n\
This door? I... I locked it.\n\
I was scared that those awful diseased\n\
spirits were in the main chamber...\n\
...What? You say it's safe? Are you sure?\n\
\n\
\n\
Well, you ARE alive... so I suppose there is no\n\
reason to doubt you. Alright, I released the\n\
lock. I apologize deeply for any trouble it caused."))

DEFINE_DIALOG(DIALOG_BUTLERGEIST_FIREPLACE, 1, 3, 30, 200, _("\
Even though the Master and Mistress\n\
do not roam the manor these days,\n\
I must still keep the fireplace warm...\n\
The flame is as bright as it will ever be,\n\
and there's even a lounging area.\n\
So just sit back and enjoy the fire.\n\
If you do decide to leave again, I suppose\n\
there is no point in keeping it secret...\n\
This manor has many hidden rooms.\n\
One even resides in here. But you will have\n\
to go back into that haunted room you came\n\
from to reach it.\n\
Many of the secrets these chambers hold\n\
are up in the rafters. Looking upward\n\
is never a bad idea."))

DEFINE_DIALOG(DIALOG_BUTLERGEIST_WELCOME, 1, 3, 30, 200, _("\
Ah! It seems we have a guest. \n\
Manor guests are rare these days...\n\
Tell me sir, what might your name be?\n\
...Mario? Well then, welcome to\n\
the Master's manor, Mario.\n\
I do feel as though I must warn you...\n\
You would find it in your best interests\n\
to remain in this chamber.\n\
The rooms around here are fine, but...\n\
I would refrain from entering the rooms\n\
down the hall. Let us just say, we have\n\
been dealing with issues beyond there.\n\
Enjoy your visit, Mr. Mario."))

DEFINE_DIALOG(DIALOG_BUTLERGEIST_ISSUES, 1, 3, 30, 200, _("\
The issues we've been dealing with?\n\
\n\
\n\
It is not an easy subject. The manor has\n\
been reduced to nothing but a haunted wreck.\n\
And not by us servants' hands mind you.\n\
We are benevolent spirits, but there have.\n\
been other ghosts about, ones that have\n\
lost their way and will.\n\
It's best you simply avoid them.\n\
I implore you try not to fight something\n\
that cannot be touched."))

DEFINE_DIALOG(DIALOG_PHANTASMAID_MASTER_CHAMBER, 1, 3, 30, 200, _("\
Beyond this door is the Master's\n\
chamber. Unfortunately, he is not\n\
seeing guests at this time.\n\
...Maybe if the Mistress was healthy\n\
again he would..."))

DEFINE_DIALOG(DIALOG_PHANTASMAID_WARNING, 1, 3, 30, 200, _("\
I won't stop you from entering here, but\n\
be warned: it is horribly dangerous.\n\
The rogue spirits will attempt to attack you.\n\
We call them Blights.\n\
Their presence here has also attracted some\n\
unruly Boos as well, to make matters worse...\n\
Just know that the Blights are not in their right minds...\n\
Unfortunate circumstances have led them to become\n\
this way, and they will likely not return to normal.\n\
Unlike Boos, you won't be able to attack them...\n\
It would be best not to provoke them, as they\n\
dislike being looked at directly."))

DEFINE_DIALOG(DIALOG_038, 1, 3, 95, 200, _("\
@FEFEFEFFWith the seal broken, Mario ventures into\n\
the dark, musty hallway ahead, with Sewnia following\n\
closely behind..."))

DEFINE_DIALOG(DIALOG_039, 0b10, 3, 30, 200, _("\
Another fallen to the wastes...\n\
Please, share a sliver of your life...\n\
Ours were taken in a long, long battle."))

DEFINE_DIALOG(DIALOG_040, 0b10, 3, 30, 200, _("\
It was centuries ago when we perished...\n\
We remember it clearly. When the war began,\n\
the realm was still a pristine blue..."))

DEFINE_DIALOG(DIALOG_041, 0b10, 3, 30, 200, _("\
Many say gods have no flaws, but\n\
they often overlook the consuming greed\n\
all powerful beings are taken by eventually..."))

DEFINE_DIALOG(DIALOG_042, 0b10, 3, 30, 200, _("\
This realm was sought after by many of the\n\
gods. And when that greed set in, a bloody\n\
war broke out..."))

DEFINE_DIALOG(DIALOG_043, 0b10, 3, 30, 200, _("\
We lost our lives early on. Mere servants could\n\
never stand up to gods. Our bodies fell to the\n\
land below and quickly polluted it with a fog..."))

DEFINE_DIALOG(DIALOG_044, 0b10, 3, 95, 200, _("\
Our spirits, however, got to witness the battles.\n\
The gods were relentless in killing each other.\n\
Their golden blood was spread throughout the sky."))

DEFINE_DIALOG(DIALOG_045, 0b10, 3, 95, 200, _("\
It became apparent that one goddess in particular\n\
had her eyes set on this realm being her dominion.\n\
Throughout the war, she reigned on top."))

DEFINE_DIALOG(DIALOG_046, 0b10, 3, 30, 200, _("\
The goddess Aurumcael...\n\
With her spear in hand, she had slain the final\n\
gods, forever dyeing the realm a deep golden color.\n\
She had won, but at the cost of the realm's\n\
beauty. The realm was now an empty graveyard.\n\
Aurumcael did not make it out unscathed though."))

DEFINE_DIALOG(DIALOG_047, 0b10, 3, 95, 200, _("\
The last gods dying to her blade bestowed a final\n\
curse upon her. One that prevented her from ever\n\
leaving the realm she had ruined.\n\
The curse also placed a shining halo on her head...\n\
One that drips burning gold that pierces her flesh,\n\
weakening her so that even a mortal can harm her."))

DEFINE_DIALOG(DIALOG_048, 0b10, 3, 30, 200, _("\
Aurumcael now resides alone in her airborne palace...\n\
The victor of a battle turned fruitless because of\n\
her..."))

DEFINE_DIALOG(DIALOG_049, 1, 3, 30, 200, _("\
Mistress...\n\
It would appear we have a guest...\n\
Are you feeling well enough to greet him?"))

DEFINE_DIALOG(DIALOG_050, 0b10, 3, 30, 200, _("\
C... Col... I...\n\
Nghh... Cold...\n\
Pl..."))

DEFINE_DIALOG(DIALOG_051, 1, 3, 30, 200, _("\
I know you are cold, Mistress...\n\
But you go into a panic when I put the covers\n\
on you. I don't wish you to harm yourself.\n\
Now, our guest here has come a far way.\n\
He might be able to help us with your affliction!\n\
Or, at least, give us hope...\n\
Mario, you have become the talk of the manor recently.\n\
After all, you arrived in the same way that evil man did.\n\
The one that did this to the poor Mistress...\n\
We were hesitant to allow you to roam freely at first.\n\
But after observing your actions, I don't believe you\n\
are here to cause harm.\n\
You have connections to that man though.\n\
That, you cannot deny. You have met him before...\n\
I can see it within your eyes... Which is why I ask this.\n\
Please, Mario, find a way to reverse this curse! \n\
Confront that man again if you must, I beg of you!\n\
The Mistress lies with a clouded mind and soul, in agony!\n\
The Master of the manor has not left his study since\n\
the attack. But I have a feeling you will meet with\n\
him soon... He has information about everything.\n\
We will help you in any way we can. Here, take this as\n\
proof of our trust and hope in you.\n\
It seems even star power wasn't enough for her..."))

DEFINE_DIALOG(DIALOG_052, 1, 5, 30, 200, _("\
Stop and press [Z] to\n\
crouch, then press [A]\n\
to do a high, Backward\n\
Somersault!\n\
\n\
To perform a Side\n\
Somersault, run, do a\n\
sharp U-turn and jump.\n\
You can catch lots of\n\
air with both jumps."))

DEFINE_DIALOG(DIALOG_053, 1, 5, 30, 200, _("\
Sometimes, if you pass\n\
through a coin ring or\n\
find a secret point in a\n\
course, a red number will\n\
appear.\n\
If you trigger five red\n\
numbers, a secret Star\n\
will show up."))

DEFINE_DIALOG(DIALOG_054, 1, 1, 30, 200, _("\
EVERYBODY, IT'S BACK! HIDE!!!"))

DEFINE_DIALOG(DIALOG_055, 1, 3, 30, 200, _("\
Mario! Watch out for its attacks!\n\
That stone ability of yours won't protect you\n\
against its piercing and spinning strikes!"))

DEFINE_DIALOG(DIALOG_056, 1, 3, 30, 200, _("\
Mario!\n\
\n\
\n\
Its trying to find its way back out of the ground!\n\
Now's the time to counterattack! Stand where it's\n\
about to burst out and use your stone ability!"))

DEFINE_DIALOG(DIALOG_057, 1, 3, 30, 200, _("\
Nice job! Now we'll help! Hop on and we'll\n\
give you a boost into the air to deliver a\n\
rock-hard blow to the Pushpin Pokey!"))

DEFINE_DIALOG(DIALOG_058, 1, 4, 30, 200, _("\
You found my precious,\n\
precious baby! Where\n\
have you been? How can\n\
I ever thank you, Mario?\n\
Oh, I do have this...\n\
...Star. Here, take it\n\
with my eternal\n\
gratitude."))

DEFINE_DIALOG(DIALOG_059, 1, 4, 30, 200, _("\
That's not my baby! She\n\
looks nothing like me!\n\
Her parents must be\n\
worried sick!"))

DEFINE_DIALOG(DIALOG_060, 1, 3, 30, 200, _("\
@C5950FFFWhy?\n\
\n\
\n\
@C5950FFFWhy does another life show itself to me?\n\
This place lost its luster long ago...\n\
And yet, you come here seeking more.\n\
@C5950FFFYou are akin to that foolish man who entered\n\
these halls years ago, asking a ludicrous feat!\n\
Something that, even to a goddess, is a miracle.\n\
@C5950FFFAnd now you stand before me, mocking\n\
me by holding a fragment of my diminished\n\
divine strength upon your cap...\n\
@C5950FFF...The very same one that\n\
man tried to overcome me with!\n\
The impertinence of it is quite ironic, no?\n\
@C5950FFFUnfortunately, that man escaped with his\n\
life. Such is the sorrow of a goddess that\n\
is trapped with this wretched curse...\n\
@C5950FFFTch! What am I doing here telling you\n\
this? Do you wish to join the spirits\n\
below that badly to step into here?\n\
@C5950FFFWhat gain have you from visiting\n\
such a broken, shattered realm anyways?\n\
There is nothing here for you!\n\
@C5950FFFThere SHOULD be nothing here!\n\
That's the way it needs to be!\n\
An empty heaven, my hell alone!"))

DEFINE_DIALOG(DIALOG_061, 0b10, 3, 30, 200, _("\
@C5950FFFHrk......\n\
\n\
\n\
@C5950FFFIT... IT BURNS!!!\n\
I CAN'T...\n\
AAUUUGHHHH!!!\n\
@C5950FFFEnough...\n\
ENOUGH!!!\n\
..."))

DEFINE_DIALOG(DIALOG_062, 1, 3, 30, 200, _("\
@C5950FFFWhat is it you want!?\n\
Power? Treasure?\n\
Or is it simply my head?\n\
@C5950FFFHow does a mortal like you\n\
even know of me!?\n\
\n\
@C5950FFF...\n\
\n\
\n\
@C5950FFFI see... So, those restless Spekturrs that\n\
remain in the abyss below told you of my\n\
past. Were you trying to avenge them? Haha...\n\
@C5950FFFPerhaps those souls have\n\
remained merely to witness my\n\
gruesome demise one day...\n\
@C5950FFFIt is regrettable in that case.\n\
I cannot be killed. Not while my\n\
curse remains, that is.\n\
@C5950FFFYou can inflict the searing pain of\n\
thousands of blades upon me, but I will\n\
never perish. Your efforts are for naught."))

DEFINE_DIALOG(DIALOG_063, 1, 3, 30, 200, _("\
@C5950FFFWhat did you say?\n\
Star Power?\n\
\n\
@C5950FFFHa... HAHAHAHA!!!\n\
\n\
\n\
@C5950FFFHere I surmised you were some valiant\n\
knight avenging restless spirits!\n\
But you're just a shallow power-seeking mortal!\n\
@C5950FFFWell... I suppose those tangents\n\
I went on were in vain. Though, you are\n\
a formidable foe... For a lousy human.\n\
@C5950FFFDo note that I would have ended your\n\
pitiful life on the spot were I at my true\n\
power, unburdened by this searing curse.\n\
@C5950FFFVery well. For your meaningless victory,\n\
you may have some of this Star Power\n\
that you seek.\n\
@C5950FFFOh but do keep in mind, if you ever\n\
enter this place again I will not\n\
hesitate to impale you. Understood?"))

DEFINE_DIALOG(DIALOG_064, 1, 5, 30, 200, _("\
When you put on the Wing\n\
Cap that comes from a\n\
red block, do the Triple\n\
Jump to soar high into\n\
the sky.\n\
Use the Control Stick to\n\
guide Mario. Pull back to\n\
to fly up, press forward\n\
to nose down, and press [Z]\n\
to land."))

DEFINE_DIALOG(DIALOG_065, 1, 6, 30, 200, _("\
Swimming Lessons!\n\
Tap [A] to do the breast\n\
stroke. If you time the\n\
taps right, you'll swim\n\
fast.\n\
\n\
Press and hold [A] to do a\n\
slow, steady flutter kick.\n\
Press Up on the Control\n\
Stick to dive, and pull\n\
back on the stick to head\n\
for the surface.\n\
To jump out of the water,\n\
hold Down on the Control\n\
Stick, then press [A].\n\
Easy as pie, right?\n\
\n\
\n\
But remember:\n\
Mario can't breathe under\n\
the water! Return to the\n\
surface for air when the\n\
Power Meter runs low.\n\
\n\
And one last thing: You\n\
can't open doors that\n\
are underwater."))

DEFINE_DIALOG(DIALOG_066, 1, 5, 30, 200, _("\
Mario, it's Peach!\n\
Please be careful! Bowser\n\
is so wicked! He will try\n\
to burn you with his\n\
horrible flame breath.\n\
Run around behind and\n\
grab him by the tail with\n\
the [B] Button. Once you\n\
grab hold, swing him\n\
around in great circles.\n\
Rotate the Control Stick\n\
to go faster and faster.\n\
The faster you swing him,\n\
the farther he'll fly.\n\
\n\
Use the [C] Buttons to look\n\
around, Mario. You have\n\
to throw Bowser into one\n\
of the bombs in the four\n\
corners.\n\
Aim well, then press [B]\n\
again to launch Bowser.\n\
Good luck, Mario! Our\n\
fate is in your hands."))

DEFINE_DIALOG(DIALOG_067, 1, 4, 30, 200, _("\
grarrrghh im gonna kill\n\
you mario!\n\
then the princess will \n\
finally be mine!\n\
bwa  haha ha"))

DEFINE_DIALOG(DIALOG_068, 1, 5, 30, 200, _("\
It's Lethal Lava Land!\n\
If you catch fire or fall\n\
into a pool of flames,\n\
you'll be hopping mad, but\n\
don't lose your cool.\n\
You can still control\n\
Mario--just try to keep\n\
calm!"))

DEFINE_DIALOG(DIALOG_069, 1, 6, 30, 200, _("\
Sometimes you'll bump into\n\
invisible walls at the\n\
edges of the painting\n\
worlds. If you hit a wall\n\
while flying, you'll bounce\n\
back."))

DEFINE_DIALOG(DIALOG_070, 1, 5, 30, 200, _("\
You can return to the\n\
castle's main hall at any\n\
time from the painting\n\
worlds where the enemies\n\
live.\n\
Just stop, stand still,\n\
press Start to pause the\n\
game, then select\n\
『Exit Course.』\n\
\n\
You don't have to collect\n\
all Power Stars in one\n\
course before going on to\n\
the next.\n\
\n\
Return later, when you're\n\
more experienced, to pick\n\
up difficult ones.\n\
\n\
\n\
Whenever you find a Star,\n\
a hint for finding the\n\
next one will appear on\n\
the course's start screen.\n\
\n\
You can, however, collect\n\
any of the remaining\n\
Stars next. You don't\n\
have to recover the one\n\
described by the hint."))

DEFINE_DIALOG(DIALOG_071, 1, 3, 30, 200, _("\
Danger Ahead!\n\
Beware of the strange\n\
cloud! Don't inhale!\n\
If you feel faint, run for\n\
higher ground and fresh\n\
air!\n\
Circle: Shelter\n\
Arrow: Entrance-Exit"))

DEFINE_DIALOG(DIALOG_072, 1, 5, 30, 200, _("\
High winds ahead!\n\
Pull your Cap down tight.\n\
If it blows off, you'll\n\
have to find it on this\n\
mountain."))

DEFINE_DIALOG(DIALOG_073, 1, 4, 95, 200, _("\
Aarrgh! Ahoy, matey. I\n\
have sunken treasure,\n\
here, I do.\n\
\n\
But to pluck the plunder,\n\
you must open the\n\
Treasure Chests in the\n\
right order.\n\
What order is that,\n\
ye say?\n\
\n\
\n\
I'll never tell!\n\
\n\
//--The Cap'n"))

DEFINE_DIALOG(DIALOG_074, 1, 5, 30, 200, _("\
You can grab on to the\n\
edge of a cliff or ledge\n\
with your fingertips and\n\
hang down from it.\n\
\n\
To drop from the edge,\n\
either press the Control\n\
Stick in the direction of\n\
Mario's back or press the\n\
[Z] Button.\n\
To get up onto the ledge,\n\
either press Up on the\n\
Control Stick or press [A]\n\
as soon as you grab the\n\
ledge to climb up quickly."))

DEFINE_DIALOG(DIALOG_075, 1, 5, 30, 200, _("\
Mario!! My castle is in\n\
great peril. I know that\n\
Bowser is the cause...and\n\
I know that only you can\n\
stop him!\n\
The doors in the castle\n\
that have been sealed by\n\
Bowser can be opened only\n\
with Star Power.\n\
\n\
But there are secret\n\
paths in the castle,\n\
paths that Bowser hasn't\n\
found.\n\
\n\
One of those paths is in\n\
this room, and it holds\n\
one of the castle's Secret\n\
Stars!\n\
\n\
Find that Secret Star,\n\
Mario! It will help you\n\
on your quest. Please,\n\
Mario, you have to\n\
help us!\n\
Retrieve all of the\n\
Power Stars in the castle\n\
and free us from this\n\
awful prison!\n\
Please!"))

DEFINE_DIALOG(DIALOG_076, 1, 6, 30, 200, _("\
Thanks to the power of\n\
the Stars, life is\n\
returning to the castle.\n\
Please, Mario, you have\n\
to give Bowser the boot!\n\
\n\
Here, let me tell you a\n\
little something about the\n\
castle. In the room with\n\
the mirrors, look carefully\n\
for anything that's not\n\
reflected in the mirror.\n\
And when you go to the\n\
water town, you can flood\n\
it with a high jump into\n\
the painting. Oh, by the\n\
way, look what I found!"))

DEFINE_DIALOG(DIALOG_077, 1, 2, 150, 200, _("\
It is decreed that one\n\
shall pound the pillars."))

DEFINE_DIALOG(DIALOG_078, 1, 5, 30, 200, _("\
Break open the Blue Coin\n\
Block by Pounding the\n\
Ground with the [Z] Button.\n\
One Blue Coin is worth\n\
five Yellow Coins.\n\
But you have to hurry!\n\
The coins will disappear\n\
if you're not quick to\n\
collect them! Too bad."))

DEFINE_DIALOG(DIALOG_ENTER_MEMORY, 1, 4, 30, 200, _("\
@FEFEFEFFA memory of an encounter\n\
appears in front of you...\n\
Revisit the encounter?\n\
//Yes    / No"))

DEFINE_DIALOG(DIALOG_080, 1, 1, 30, 200, _("\
Eeeh hee hee hee!"))

DEFINE_DIALOG(DIALOG_081, 1, 4, 30, 200, _("\
The mystery is of Wet\n\
or Dry.\n\
And where does the\n\
solution lie?\n\
The city welcomes visitors\n\
with the depth they bring\n\
as they enter."))

DEFINE_DIALOG(DIALOG_082, 1, 4, 30, 200, _("\
Hold on to your hat! If\n\
you lose it, you'll be\n\
injured easily.\n\
\n\
If you do lose your Cap,\n\
you'll have to find it in\n\
the course where you\n\
lost it.\n\
Oh, boy, it's not looking\n\
good for Peach. She's\n\
still trapped somewhere\n\
inside the walls.\n\
Please, Mario, you have\n\
to help her! Did you know\n\
that there are enemy\n\
worlds inside the walls?\n\
Yup. It's true. Bowser's\n\
troops are there, too.\n\
Oh, here, take this. I've\n\
been keeping it for you."))

DEFINE_DIALOG(DIALOG_083, 1, 6, 30, 200, _("\
There's something strange\n\
about that clock. As you\n\
jump inside, watch the\n\
position of the big hand.\n\
Oh, look what I found!\n\
Here, Mario, catch!"))

DEFINE_DIALOG(DIALOG_084, 1, 3, 30, 200, _("\
Yeeoww! Unhand me,\n\
brute! I'm late, so late,\n\
I must make haste!\n\
This shiny thing? Mine!\n\
It's mine. Finders,\n\
keepers, losers...\n\
Late, late, late...\n\
Ouch! Take it then! A\n\
gift from Bowser, it was.\n\
Now let me be! I have a\n\
date! I cannot be late\n\
for tea!"))

DEFINE_DIALOG(DIALOG_085, 1, 5, 30, 200, _("\
You don't stand a ghost\n\
of a chance in this house.\n\
If you walk out of here,\n\
you deserve...\n\
...a Ghoul Medal..."))

DEFINE_DIALOG(DIALOG_086, 1, 3, 30, 200, _("\
Running around in circles\n\
makes some bad guys roll\n\
their eyes."))

DEFINE_DIALOG(DIALOG_087, 1, 4, 30, 200, _("\
Santa Claus isn't the only\n\
one who can go down a\n\
chimney! Come on in!\n\
/--Cabin Proprietor"))

DEFINE_DIALOG(DIALOG_088, 1, 5, 30, 200, _("\
Work Elevator\n\
For those who get off\n\
here: Grab the pole to the\n\
left and slide carefully\n\
down."))

DEFINE_DIALOG(DIALOG_089, 1, 5, 95, 200, _("\
Both ways fraught with\n\
danger! Watch your feet!\n\
Those who can't do the\n\
Long Jump, tsk, tsk. Make\n\
your way to the right.\n\
Right: Work Elevator\n\
/// Cloudy Maze\n\
Left: Black Hole\n\
///Underground Lake\n\
\n\
Red Circle: Elevator 2\n\
//// Underground Lake\n\
Arrow: You are here"))

DEFINE_DIALOG(DIALOG_090, 1, 6, 30, 200, _("\
Bwa ha ha ha!\n\
You've stepped right into\n\
my trap, just as I knew\n\
you would! I warn you,\n\
『Friend,』 watch your\n\
step!"))

DEFINE_DIALOG(DIALOG_091, 2, 2, 30, 200, _("\
Danger!\n\
Strong Gusts!\n\
But the wind makes a\n\
comfy ride."))

DEFINE_DIALOG(DIALOG_092, 1, 5, 30, 200, _("\
Pestering me again, are\n\
you, Mario? Can't you see\n\
that I'm having a merry\n\
little time, making\n\
mischief with my minions?\n\
Now, return those Stars!\n\
My troops in the walls\n\
need them! Bwa ha ha!"))

DEFINE_DIALOG(DIALOG_093, 1, 5, 30, 200, _("\
Mario! You again! Well\n\
that's just fine--I've\n\
been looking for something\n\
to fry with my fire\n\
breath!\n\
Your Star Power is\n\
useless against me!\n\
Your friends are all\n\
trapped within the\n\
walls...\n\
And you'll never see the\n\
Princess again!\n\
Bwa ha ha ha!"))

DEFINE_DIALOG(DIALOG_094, 1, 4, 30, 200, _("\
Get a good run up the\n\
slope! Do you remember\n\
the Long Jump? Run, press\n\
[Z], then jump!"))

DEFINE_DIALOG(DIALOG_095, 1, 4, 30, 200, _("\
To read a sign, stand in\n\
front of it and press [B],\n\
like you did just now.\n\
\n\
When you want to talk to\n\
a Koopa Troopa or other\n\
animal, stand right in\n\
front of it.\n\
Please recover the Stars\n\
that were stolen by\n\
Bowser in this course."))

DEFINE_DIALOG(DIALOG_096, 1, 4, 30, 200, _("\
The path is narrow here.\n\
Easy does it! No one is\n\
allowed on top of the\n\
mountain!\n\
And if you know what's\n\
good for you, you won't\n\
wake anyone who's\n\
sleeping!\n\
Move slowly,\n\
tread lightly."))

DEFINE_DIALOG(DIALOG_097, 1, 5, 30, 200, _("\
Don't be a pushover!\n\
If anyone tries to shove\n\
you around, push back!\n\
It's one-on-one, with a\n\
fiery finish for the loser!"))

DEFINE_DIALOG(DIALOG_098, 1, 2, 95, 200, _("\
Come on in here...\n\
...heh, heh, heh..."))

// unused
DEFINE_DIALOG(DIALOG_099, 1, 5, 95, 200, _("\
Eh he he...\n\
You're mine, now, hee hee!\n\
I'll pass right through\n\
this wall. Can you do\n\
that? Heh, heh, heh!"))

DEFINE_DIALOG(DIALOG_100, 1, 3, 95, 200, _("\
Ukkiki...Wakkiki...kee kee!\n\
Ha! I snagged it!\n\
It's mine! Heeheeheeee!"))

DEFINE_DIALOG(DIALOG_101, 1, 3, 95, 200, _("\
Ackk! Let...go...\n\
You're...choking...me...\n\
Cough...I've been framed!\n\
This Cap? Oh, all right,\n\
take it. It's a cool Cap,\n\
but I'll give it back.\n\
I think it looks better on\n\
me than it does on you,\n\
though! Eeeee! Kee keee!"))

DEFINE_DIALOG(DIALOG_102, 1, 5, 30, 200, _("\
Pssst! The Boos are super\n\
shy. If you look them\n\
in the eyes, they fade\n\
away, but if you turn\n\
your back, they reappear.\n\
It's no use trying to hit\n\
them when they're fading\n\
away. Instead, sneak up\n\
behind them and punch."))

DEFINE_DIALOG(DIALOG_103, 1, 4, 95, 200, _("\
Upon four towers\n\
one must alight...\n\
Then at the peak\n\
shall shine the light..."))

DEFINE_DIALOG(DIALOG_104, 1, 5, 30, 200, _("\
The shadowy star in front\n\
of you is a 『Star\n\
Marker.』 When you collect\n\
all 8 Red Coins, the Star\n\
will appear here."))

DEFINE_DIALOG(DIALOG_105, 1, 3, 95, 200, _("\
Ready for blastoff! Come\n\
on, hop into the cannon!\n\
\n\
You can reach the Star on\n\
the floating island by\n\
using the four cannons.\n\
Use the Control Stick to\n\
aim, then press [A] to fire.\n\
\n\
If you're handy, you can\n\
grab on to trees or poles\n\
to land."))

DEFINE_DIALOG(DIALOG_106, 1, 2, 95, 200, _("\
Ready for blastoff! Come\n\
on, hop into the cannon!"))

DEFINE_DIALOG(DIALOG_107, 1, 3, 95, 200, _("\
Ghosts...\n\
...don't...\n\
...DIE!\n\
Heh, heh, heh!\n\
Can you get out of here...\n\
...alive?"))

DEFINE_DIALOG(DIALOG_108, 1, 2, 95, 200, _("\
Boooooo-m! Here comes\n\
the master of mischief,\n\
the tower of terror,\n\
the Big Boo!\n\
Ka ha ha ha..."))

DEFINE_DIALOG(DIALOG_109, 1, 4, 95, 200, _("\
Ooooo Nooooo!\n\
Talk about out-of-body\n\
experiences--my body\n\
has melted away!\n\
Have you run in to any\n\
headhunters lately??\n\
I could sure use a new\n\
body!\n\
Brrr! My face might\n\
freeze like this!"))

DEFINE_DIALOG(DIALOG_110, 1, 5, 95, 200, _("\
I need a good head on my\n\
shoulders. Do you know of\n\
anybody in need of a good\n\
body? Please! I'll follow\n\
you if you do!"))

DEFINE_DIALOG(DIALOG_111, 1, 4, 95, 200, _("\
Perfect! What a great\n\
new body! Here--this is a\n\
present for you. It's sure\n\
to warm you up."))

DEFINE_DIALOG(DIALOG_112, 1, 4, 30, 200, _("\
Collect as many coins as\n\
possible! They'll refill\n\
your Power Meter.\n\
\n\
You can check to see how\n\
many coins you've\n\
collected in each of the\n\
15 enemy worlds.\n\
You can also recover\n\
power by touching the\n\
Spinning Heart.\n\
\n\
The faster you run\n\
through the heart, the\n\
more power you'll recover."))

DEFINE_DIALOG(DIALOG_113, 1, 6, 30, 200, _("\
There are special Caps in\n\
the red, green and blue\n\
blocks. Step on the\n\
switches in the hidden\n\
courses to activate the\n\
Cap Blocks."))

DEFINE_DIALOG(DIALOG_114, 1, 5, 95, 200, _("\
It makes me so mad! We\n\
build your houses, your\n\
castles. We pave your\n\
roads, and still you\n\
walk all over us.\n\
Do you ever say thank\n\
you? No! Well, you're not\n\
going to wipe your feet\n\
on me! I think I'll crush\n\
you just for fun!\n\
Do you have a problem\n\
with that? Just try to\n\
pound me, wimp! Ha!"))

DEFINE_DIALOG(DIALOG_115, 1, 5, 95, 200, _("\
No! Crushed again!\n\
I'm just a stepping stone,\n\
after all. I won't gravel,\n\
er, grovel. Here, you win.\n\
Take this with you!"))

DEFINE_DIALOG(DIALOG_116, 1, 5, 95, 200, _("\
Whaaa....Whaaat?\n\
Can it be that a\n\
pipsqueak like you has\n\
defused the Bob-omb\n\
king????\n\
You might be fast enough\n\
to ground me, but you'll\n\
have to pick up the pace\n\
if you want to take King\n\
Bowser by the tail.\n\
Methinks my troops could\n\
learn a lesson from you!\n\
Here is your Star, as I\n\
promised, Mario.\n\
\n\
If you want to see me\n\
again, select this Star\n\
from the menu. For now,\n\
farewell."))

DEFINE_DIALOG(DIALOG_117, 1, 1, 95, 200, _("\
Who...walk...here?\n\
Who...break...seal?\n\
Wake..ancient..ones?\n\
We no like light...\n\
Rrrrummbbble...\n\
We no like...intruders!\n\
Now battle...\n\
...hand...\n\
...to...\n\
...hand!"))

DEFINE_DIALOG(DIALOG_118, 1, 6, 95, 200, _("\
Grrrrumbbble!\n\
What...happen?\n\
We...crushed like pebble.\n\
You so strong!\n\
You rule ancient pyramid!\n\
For today...\n\
Now, take Star of Power.\n\
We...sleep...darkness."))

DEFINE_DIALOG(DIALOG_119, 1, 6, 30, 200, _("\
Grrr! I was a bit\n\
careless. This is not as I\n\
had planned...but I still\n\
hold the power of the\n\
Stars, and I still have\n\
Peach.\n\
Bwa ha ha! You'll get no\n\
more Stars from me! I'm\n\
not finished with you yet,\n\
but I'll let you go for\n\
now. You'll pay for this...\n\
later!"))

DEFINE_DIALOG(DIALOG_120, 1, 4, 30, 200, _("\
Ooowaah! Can it be that\n\
I've lost??? The power of\n\
the Stars has failed me...\n\
this time.\n\
Consider this a draw.\n\
Next time, I'll be in\n\
perfect condition.\n\
\n\
Now, if you want to see\n\
your precious Princess,\n\
come to the top of the\n\
tower.\n\
I'll be waiting!\n\
Gwa ha ha ha!"))

DEFINE_DIALOG(DIALOG_121, 1, 5, 30, 200, _("\
Nooo! It can't be!\n\
You've really beaten me,\n\
Mario?!! I gave those\n\
troops power, but now\n\
it's fading away!\n\
Arrgghh! I can see peace\n\
returning to the world! I\n\
can't stand it! Hmmm...\n\
It's not over yet...\n\
\n\
C'mon troops! Let's watch\n\
the ending together!\n\
Bwa ha ha!"))

DEFINE_DIALOG(DIALOG_122, 1, 4, 30, 200, _("\
The Black Hole\n\
Right: Work Elevator\n\
/// Cloudy Maze\n\
Left: Underground Lake"))

DEFINE_DIALOG(DIALOG_123, 1, 4, 30, 200, _("\
Metal Cavern\n\
Right: To Waterfall\n\
Left: Metal Cap Switch"))

DEFINE_DIALOG(DIALOG_124, 1, 4, 30, 200, _("\
Work Elevator\n\
Danger!!\n\
Read instructions\n\
thoroughly!\n\
Elevator continues in the\n\
direction of the arrow\n\
activated."))

DEFINE_DIALOG(DIALOG_RECOVERED_KEY, 1, 3, 30, 200, _("\
@FEFEFEFFYou've recovered a key to the lockbox.\n\
With the key in hand, Mario feels\n\
a flow of secrets in his head...\n\
@FEFEFEFFThe Patchmaker awaits within\n\
the realm of betweens...\n\
You now have access to The Brink."))

DEFINE_DIALOG(DIALOG_126, 2, 3, 30, 200, _("\
Up: Black Hole\n\
Right: Work Elevator\n\
/// Hazy Maze"))

DEFINE_DIALOG(DIALOG_127, 3, 4, 30, 200, _("\
Underground Lake\n\
Right: Metal Cave\n\
Left: Abandoned Mine\n\
///(Closed)\n\
A gentle sea dragon lives\n\
here. Pound on his back to\n\
make him lower his head.\n\
Don't become his lunch."))

DEFINE_DIALOG(DIALOG_128, 1, 4, 95, 200, _("\
You must fight with\n\
honor! It is against the\n\
royal rules to throw the\n\
king out of the ring!"))

DEFINE_DIALOG(DIALOG_129, 1, 5, 30, 200, _("\
Welcome to the Vanish\n\
Cap Switch Course! All of\n\
the blue blocks you find\n\
will become solid once you\n\
step on the Cap Switch.\n\
You'll disappear when you\n\
put on the Vanish Cap, so\n\
you'll be able to elude\n\
enemies and walk through\n\
many things. Try it out!"))

DEFINE_DIALOG(DIALOG_130, 1, 5, 30, 200, _("\
Welcome to the Metal Cap\n\
Switch Course! Once you\n\
step on the Cap Switch,\n\
the green blocks will\n\
become solid.\n\
When you turn your body\n\
into metal with the Metal\n\
Cap, you can walk\n\
underwater! Try it!"))

DEFINE_DIALOG(DIALOG_131, 1, 5, 30, 200, _("\
Welcome to the Wing Cap\n\
Course! Step on the red\n\
switch at the top of the\n\
tower, in the center of\n\
the rainbow ring.\n\
When you trigger the\n\
switch, all of the red\n\
blocks you find will\n\
become solid.\n\
\n\
Try out the Wing Cap! Do\n\
the Triple Jump to take\n\
off and press [Z] to land.\n\
\n\
\n\
Pull back on the Control\n\
Stick to go up and push\n\
forward to nose down,\n\
just as you would when\n\
flying an airplane."))

DEFINE_DIALOG(DIALOG_132, 1, 4, 30, 200, _("\
Whoa, Mario, pal, you\n\
aren't trying to cheat,\n\
are you? Shortcuts aren't\n\
allowed.\n\
Now, I know that you\n\
know better. You're\n\
disqualified! Next time,\n\
play fair!"))

DEFINE_DIALOG(DIALOG_133, 1, 6, 30, 200, _("\
Am I glad to see you! The\n\
Princess...and I...and,\n\
well, everybody...we're all\n\
trapped inside the castle\n\
walls.\n\
\n\
Bowser has stolen the\n\
castle's Stars, and he's\n\
using their power to\n\
create his own world in\n\
the paintings and walls.\n\
\n\
Please recover the Power\n\
Stars! As you find them,\n\
you can use their power\n\
to open the doors that\n\
Bowser has sealed.\n\
\n\
There are four rooms on\n\
the first floor. Start in\n\
the one with the painting\n\
of Bob-omb inside. It's\n\
the only room that Bowser\n\
hasn't sealed.\n\
When you collect eight\n\
Power Stars, you'll be\n\
able to open the door\n\
with the big star. The\n\
Princess must be inside!"))

DEFINE_DIALOG(DIALOG_134, 1, 5, 30, 200, _("\
The names of the Stars\n\
are also hints for\n\
finding them. They are\n\
displayed at the beginning\n\
of each course.\n\
You can collect the Stars\n\
in any order. You won't\n\
find some Stars, enemies\n\
or items unless you select\n\
a specific Star.\n\
After you collect some\n\
Stars, you can try\n\
another course.\n\
We're all waiting for\n\
your help!"))

DEFINE_DIALOG(DIALOG_135, 1, 5, 30, 200, _("\
It was Bowser who stole\n\
the Stars. I saw him with\n\
my own eyes!\n\
\n\
\n\
He's hidden six Stars in\n\
each course, but you\n\
won't find all of them in\n\
some courses until you\n\
press the Cap Switches.\n\
The Stars you've found\n\
will show on each course's\n\
starting screen.\n\
\n\
\n\
If you want to see some\n\
of the enemies you've\n\
already defeated, select\n\
the Stars you recovered\n\
from them."))

DEFINE_DIALOG(DIALOG_136, 1, 6, 30, 200, _("\
Wow! You've already\n\
recovered that many\n\
Stars? Way to go, Mario!\n\
I'll bet you'll have us out\n\
of here in no time!\n\
\n\
Be careful, though.\n\
Bowser and his band\n\
wrote the book on 『bad.』\n\
Take my advice: When you\n\
need to recover from\n\
injuries, collect coins.\n\
Yellow Coins refill one\n\
piece of the Power Meter,\n\
Red Coins refill two\n\
pieces, and Blue Coins\n\
refill five.\n\
\n\
To make Blue Coins\n\
appear, pound on Blue\n\
Coin Blocks.\n\
\n\
\n\
\n\
Also, if you fall from\n\
high places, you'll\n\
minimize damage if you\n\
Pound the Ground as you\n\
land."))

DEFINE_DIALOG(DIALOG_137, 1, 6, 30, 200, _("\
Thanks, Mario! The castle\n\
is recovering its energy\n\
as you retrieve Power\n\
Stars, and you've chased\n\
Bowser right out of here,\n\
on to some area ahead.\n\
Oh, by the by, are you\n\
collecting coins? Special\n\
Stars appear when you\n\
collect 100 coins in each\n\
of the 15 courses!"))

DEFINE_DIALOG(DIALOG_138, 1, 3, 30, 200, _("\
Down: Underground Lake\n\
Left: Black Hole\n\
Right: Hazy Maze (Closed)"))

DEFINE_DIALOG(DIALOG_139, 1, 6, 30, 200, _("\
Above: Automatic Elevator\n\
Elevator begins\n\
automatically and follows\n\
pre-set course.\n\
It disappears\n\
automatically, too."))

DEFINE_DIALOG(DIALOG_140, 1, 6, 30, 200, _("\
Elevator Area\n\
Right: Hazy Maze\n\
/// Entrance\n\
Left: Black Hole\n\
///Elevator 1\n\
Arrow: You are here"))

DEFINE_DIALOG(DIALOG_141, 1, 5, 150, 200, _("\
You've recovered one of\n\
the stolen Power Stars!\n\
Now you can open some of\n\
the sealed doors in the\n\
castle.\n\
Try the Princess's room\n\
on the second floor and\n\
the room with the\n\
painting of Whomp's\n\
Fortress on Floor 1.\n\
Bowser's troops are still\n\
gaining power, so you\n\
can't give up. Save us,\n\
Mario! Keep searching for\n\
Stars!"))

DEFINE_DIALOG(DIALOG_142, 1, 5, 150, 200, _("\
You've recovered three\n\
Power Stars! Now you can\n\
open any door with a 3\n\
on its star.\n\
\n\
You can come and go from\n\
the open courses as you\n\
please. The enemies ahead\n\
are even meaner, so be\n\
careful!"))

DEFINE_DIALOG(DIALOG_143, 1, 6, 150, 200, _("\
You've recovered eight of\n\
the Power Stars! Now you\n\
can open the door with\n\
the big Star! But Bowser\n\
is just ahead...can you\n\
hear the Princess calling?"))

DEFINE_DIALOG(DIALOG_144, 1, 6, 150, 200, _("\
You've recovered 30\n\
Power Stars! Now you can\n\
open the door with the\n\
big Star! But before you\n\
move on, how's it going\n\
otherwise?\n\
Did you pound the two\n\
columns down? You didn't\n\
lose your hat, did you?\n\
If you did, you'll have to\n\
stomp on the condor to\n\
get it back!\n\
They say that Bowser has\n\
sneaked out of the sea\n\
and into the underground.\n\
Have you finally\n\
cornered him?"))

DEFINE_DIALOG(DIALOG_145, 1, 6, 150, 200, _("\
You've recovered 50\n\
Power Stars! Now you can\n\
open the Star Door on the\n\
third floor. Bowser's\n\
there, you know.\n\
\n\
Oh! You've found all of\n\
the Cap Switches, haven't\n\
you? Red, green and blue?\n\
The Caps you get from the\n\
colored blocks are really\n\
helpful.\n\
Hurry along, now. The\n\
third floor is just ahead."))

DEFINE_DIALOG(DIALOG_146, 1, 6, 150, 200, _("\
You've found 70 Power\n\
Stars! The mystery of the\n\
endless stairs is solved,\n\
thanks to you--and is\n\
Bowser ever upset! Now,\n\
on to the final bout!"))

DEFINE_DIALOG(DIALOG_147, 1, 5, 30, 200, _("\
Are you using the Cap\n\
Blocks? You really should,\n\
you know.\n\
\n\
\n\
To make them solid so you\n\
can break them, you have\n\
to press the colored Cap\n\
Switches in the castle's\n\
hidden courses.\n\
You'll find the hidden\n\
courses only after\n\
regaining some of the\n\
Power Stars.\n\
\n\
The Cap Blocks are a big\n\
help! Red for the Wing\n\
Cap, green for the Metal\n\
Cap, blue for the Vanish\n\
Cap."))

DEFINE_DIALOG(DIALOG_148, 1, 6, 30, 200, _("\
Snowman Mountain ahead.\n\
Keep out! And don't try\n\
the Triple Jump over the\n\
ice block shooter.\n\
\n\
\n\
If you fall into the\n\
freezing pond, your power\n\
decreases quickly, and\n\
you won't recover\n\
automatically.\n\
//--The Snowman"))

DEFINE_DIALOG(DIALOG_149, 1, 3, 30, 200, _("\
Welcome to\n\
Princess Toadstool's\n\
secret slide!\n\
There's a Star hidden\n\
here that Bowser couldn't\n\
find.\n\
When you slide, press\n\
forward to speed up,\n\
pull back to slow down.\n\
If you slide really\n\
fast, you'll win the Star!"))

DEFINE_DIALOG(DIALOG_150, 1, 5, 30, 200, _("\
Waaaa! You've flooded my\n\
house! Wh-why?? Look at\n\
this mess! What am I\n\
going to do now?\n\
\n\
The ceiling's ruined, the\n\
floor is soaked...what to\n\
do, what to do? Huff...\n\
huff...it makes me so...\n\
MAD!!!\n\
Everything's been going\n\
wrong ever since I got\n\
this Star...It's so shiny,\n\
but it makes me feel...\n\
strange..."))

DEFINE_DIALOG(DIALOG_151, 1, 4, 30, 200, _("\
I can't take this\n\
anymore! First you get\n\
me all wet, then you\n\
stomp on me!\n\
Now I'm really, really,\n\
REALLY mad!\n\
Waaaaaaaaaaaaaaaaa!!!"))

DEFINE_DIALOG(DIALOG_152, 1, 3, 30, 200, _("\
Owwch! Uncle! Uncle!\n\
Okay, I give up. Take this\n\
Star!\n\
Whew! I feel better now.\n\
I don't really need it\n\
anymore, anyway--\n\
I can see the stars\n\
through my ceiling at\n\
night.\n\
They make me feel...\n\
...peaceful. Please, come\n\
back and visit anytime."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_HUB_2_1, 1, 3, 30, 200, _("\
@7F60B4FFI used to love this place, you know.\n\
The Patchmaker, after creating me, decided he\n\
would make this area a sort of kids' museum.\n\
@7F60B4FFI always gave him honest feedback on\n\
what I thought was wonderful and inspiring.\n\
I hoped one day to make a bunch of friends here.\n\
@7F60B4FFNow, I'm friends with you and Mr. Bowser!"))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_HUB_2_2, 1, 4, 30, 200, _("\
@7F60B4FFI'm still a little shaken up from\n\
the encounter with The Patchmaker...\n\
I know you did all the confrontation, but\n\
I still hated seeing him like that.\n\
@7F60B4FFI'm a little scared of what would happen\n\
if he saw me again. I've been hiding from him\n\
for a long time. His insanity only gets\n\
worse when he sees me..."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_HUB_2_3, 1, 3, 30, 200, _("\
@7F60B4FFI really hope we can find Princess Peach's\n\
thread. It's lucky that I even found Mr. Bowser's.\n\
It was just lying around in a box.\n\
@7F60B4FFThe Patchmaker did always have a spot for\n\
beautiful things though... If Princess Peach is like\n\
what you describe, her thread may be out somewhere."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_25_STARS_1, 1, 5, 30, 200, _("\
@7F60B4FFHow have the worlds around here been treating you?\n\
Unlike the last area, these worlds were reached\n\
with better destination intent.\n\
@7F60B4FFThe Patchmaker wanted to find any method of\n\
creating life, so he followed any lead he\n\
could think of...\n\
@7F60B4FFWhether that be the sea, through spirits,\n\
or places that may only exist in fiction..."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_25_STARS_2, 1, 3, 30, 200, _("\
@7F60B4FFYou know, Bowser really has been looking\n\
hard for Princess Peach's thread.\n\
He must care about her a lot...\n\
@7F60B4FFThough... he has told me what he's\n\
done to try and woo her over in the past.\n\
His methods are... uh...\n\
@7F60B4FF...Anyways, I know why you two\n\
fight so much now."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_ENOUGH_STARS_HUB_2, 1, 2, 30, 200, _("\
@7F60B4FFWow... I can practically feel\n\
the star power radiating off of you!\n\
@7F60B4FFI think this is more than enough to\n\
shatter the barrier!"))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_HUB_3_1, 1, 3, 30, 200, _("\
@7F60B4FFI have a horrid feeling...\n\
I'm really scared about what The Patchmaker\n\
is doing, Mario.\n\
@7F60B4FFHe can't be thinking coherently anymore,\n\
if at all...\n\
Which means he could be doing anything.\n\
@7F60B4FFHe's only scary now.\n\
This image of him is...\n\
Destroying the past."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_HUB_3_2, 1, 3, 30, 200, _("\
@7F60B4FFThe last time I stepped foot in here,\n\
it was horrifying.\n\
I'd rather not discuss it...\n\
@7F60B4FFIt seems at the very least,\n\
he got rid of them.\n\
I'm scared to know where they are now..."))

#ifdef VERSION_EU
#define KEEP_ON_PLAYING ".."
#else
#define KEEP_ON_PLAYING "\n\
We want you to keep on\n\
playing, so we have a\n\
little something for you.\n\
We hope that you like it!\n\
Enjoy!!!"
#endif

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_HUB_3_3, 1, 3, 30, 200, _("\
@7F60B4FFPrincess Peach really has been trying\n\
hard to cheer me up.\n\
It's been nice...\n\
@7F60B4FFBut... I just can't stop\n\
thinking about what happened.\n\
I feel so scared...\n\
@7F60B4FFPlease, Mario...\n\
Put an end to The Patchmaker soon..."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_ENOUGH_STARS_TS, 1, 3, 30, 200, _("\
@7F60B4FFI think you would be able to enter\n\
the dimension the lockbox came from with\n\
that much star power...\n\
@7F60B4FFIt might be hard to find,\n\
but I'm positive a key exists there.\n\
Keep an eye out, Mario."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_LOCKBOX_KEY_FOUND, 1, 3, 30, 200, _("\
@7F60B4FFCongratulations on finding the key...\n\
Whenever you're ready, the lockbox\n\
should open for you."))

DEFINE_DIALOG(DIALOG_ENTERING_THIRD_HUB, 1, 3, 30, 200, _("\
@FF0202FFWoah!\n\
\n\
\n\
@FF0202FFThis place is even weirder...\n\
\n\
\n\
@7F60B4FFThis place has some of The Patchmaker's\n\
most abstract creations...\n\
Some of the works span an entire room.\n\
@7F60B4FFWait... no...\n\
It couldn't be!\n\
\n\
@7F60B4FFDid he enter the lockbox!?\n\
\n\
\n\
@FF75DFFFWhatever does that mean?\n\
You're saying he fled inside of that\n\
small trinket?\n\
@7F60B4FFIt's not just a trinket...\n\
Inside, there's an entire pocket\n\
dimension filled with lost souls.\n\
@7F60B4FFThat's where he was getting\n\
the spirits he bound to dolls in his\n\
attempts to recreate... me...\n\
@7F60B4FFIf he's in there, it means he could\n\
continue binding souls and trapping them!\n\
\n\
@FF75DFFFHold on a second...\n\
You said he was trying to create life, right?\n\
Didn't he accomplish it with this, then?\n\
@7F60B4FFNo... Every single soul he bound\n\
turned out to be a failure. The results...\n\
They were hardly alive. More like zombies.\n\
@7F60B4FFHe wasn't satisfied, and so,\n\
many souls were trapped in dolls...\n\
This... can't continue.\n\
@FF0202FFWell, if you wanna stop him,\n\
that thing looks like it's locked.\n\
I could try to bust it open...\n\
@7F60B4FFDon't! Who knows what could happen?\n\
Listen... He found this artifact within a shrine\n\
built in a universe of its own...\n\
@7F60B4FFWe may be able to find another key there.\n\
Mario, there should be a gate to it somewhere here...\n\
But you'll need more star power to reopen it.\n\
@7F60B4FFThankfully, there are more portals here...\n\
But these areas are quite scary.\n\
Be careful if you collect star power here...\n\
@FF0202FFSo you're saying I gotta wait on Mario AGAIN!?\n\
Well, Peach is waiting here with me so it's\n\
actually very nice! Bwahaha!\n\
@FF75DFFF..."))

DEFINE_DIALOG(DIALOG_ENTERING_BRINK, 1, 3, 30, 200, _("\
@7F60B4FFSo... this is it.\n\
Thank you so much, Mario.\n\
It means a lot that you did this for me.\n\
@7F60B4FFI... can't imagine what The Patchmaker\n\
is doing in there. I'm scared for the\n\
souls wandering inside.\n\
@7F60B4FFThe power of the stars you collected\n\
should keep you safe from the strong\n\
energy there. Otherwise it would tear you apart...\n\
@FF0202FFGrr...\n\
I want to pummel him SO BAD!!!\n\
Mario! You better be ruthless for me!\n\
@FF75DFFFPlease be careful, Mario...\n\
I know you can do this, but don't\n\
push yourself. This is scary territory.\n\
@7F60B4FFDon't hold back, Mario... Please...\n\
That man in there... He isn't my father.\n\
None of my father is left in him.\n\
@7F60B4FFI'm scared to know what this pocket realm\n\
has done to his physical form...\n\
If he's even alive still.\n\
@7F60B4FFBut I need to know that nobody else\n\
will be hurt.\n\
\n\
@7F60B4FFSo please... for the memory of my father.\n\
Please defeat him once and for all."))

DEFINE_DIALOG(DIALOG_FINAL_BOSS_DEFEATED_1, 1, 3, 30, 200, _("\
@FF75DFFF...up.\n\
\n\
\n\
@FF75DFFF...wake up...\n\
\n\
\n\
@FF75DFFFMario, please! Wake up!"))

DEFINE_DIALOG(DIALOG_FINAL_BOSS_DEFEATED_2, 1, 3, 30, 200, _("\
@FF75DFFFThank goodness!\n\
You're ok!!!\n\
\n\
@FF0202FFHrmph! Please...\n\
I TOLD you he'd be fine.\n\
He's not easy to get rid of...\n\
@7F60B4FFMario... Welcome back.\n\
I'm so glad you're okay...\n\
Look over here...\n\
@7F60B4FFThe souls in the lockbox\n\
are being freed.\n\
The Patchmaker can't hurt them any more...\n\
@FF75DFFFThey're beautiful...\n\
I can't imagine how sad they felt\n\
being half-bound to dolls...\n\
@7F60B4FFYeah...\n\
\n\
\n\
@FF75DFFFSewnia, what's wrong?\n\
Are you... thinking about him?\n\
\n\
@7F60B4FFMhm... He's finally free, too.\n\
The memories I cherished can't be\n\
tarnished any more...\n\
@7F60B4FFI'll never forget the incredible\n\
man he used to be. Even if what he became\n\
was a mad, unforgivable monster.\n\
@FF0202FFBuck up, kid.\n\
I'm sure your pops would have been\n\
real proud of you for toughing this out.\n\
@7F60B4FFI just...\n\
What...\n\
What now?\n\
@7F60B4FFThis place was my entire life.\n\
But now... I have no reason to stay here...\n\
What do I even do now?\n\
@FF75DFFFAh...\n\
Don't worry, Sewnia. You'll figure it out.\n\
There is so much to see in this world.\n\
@FF75DFFFYou are more than welcome\n\
to stay at my castle while you\n\
figure it all out.\n\
@7F60B4FFThank...\n\
Thank you, Peach.\n\
\n\
@FF0202FFFine, since nobody else is saying it,\n\
can we FINALLY leave this place? I'll NEVER\n\
get this mustiness off my shell at this rate!\n\
@FF75DFFFI agree with Bowser!\n\
A pleasant walk will help you take a breath\n\
and think about what to do next.\n\
@FF75DFFFSewnia, can you show us the way?\n\
\n\
\n\
@7F60B4FFOf course... Follow me.\n\
Let's see outside after all we've accomplished.\n\
Coming, Mario?"))

DEFINE_DIALOG(DIALOG_168, 1, 5, 30, 200, _("\
Hey! Knock it off! That's\n\
the second time you've\n\
nailed me. Now you're\n\
asking for it, linguine\n\
breath!"))

DEFINE_DIALOG(DIALOG_169, 1, 4, 30, 200, _("\
Keep out!\n\
That means you!\n\
Arrgghh!\n\
\n\
Anyone entering this cave\n\
without permission will\n\
meet certain disaster."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_BEGINNING_1, 1, 3, 30, 200, _("\
@7F60B4FFI never thought I would see somebody\n\
else in here...\n\
Umm... I hope it isn't too dusty..."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_BEGINNING_2, 1, 3, 30, 200, _("\
@7F60B4FFYour clothes are kind of funny...\n\
Why are they so bright?\n\
I thought clothes were darker than that.\n\
@7F60B4FF...Huh? Clothes can be any color?\n\
That's odd. The only clothes I've\n\
seen have been quite dull."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_BEGINNING_3, 1, 3, 30, 200, _("\
@7F60B4FFYou're from outside of here, right?\n\
What's it like? I have only been in\n\
the forest right outside before.\n\
@7F60B4FF...The Mushroom Kingdom?\n\
Haha, you're funny! I haven't\n\
heard of a crazy place like that before!\n\
@7F60B4FFHey, if that's where you're truly from,\n\
do you think it's far away from here?\n\
It sounds really fun..."))

DEFINE_DIALOG(DIALOG_SEWNIA_STONE_PATCH_FOUND, 1, 3, 30, 200, _("\
@7F60B4FFYou look a little shaken...\n\
Was using the stone patch for the first\n\
time that scary?\n\
@7F60B4FFThe Patchmaker was actually really proud\n\
of making that. It was how he got his\n\
nickname after all.\n\
@7F60B4FFHe did tell me that the magic in it\n\
does make the user confused for a\n\
short period of time.\n\
@7F60B4FFBut don't worry! It shouldn't\n\
happen again!\n\
...And sorry for not warning you."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_POST_PATCH_FOUND_1, 1, 3, 30, 200, _("\
@7F60B4FFMario, Mario, Ma-ri-o!\n\
Mario. Mario! Ma. Ri. O!!!\n\
Hehe... your name is fun to say!"))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_POST_PATCH_FOUND_2, 1, 4, 30, 200, _("\
@7F60B4FFI hope the worlds you're visiting aren't\n\
causing you too much trouble...\n\
I have to say I feel really bad about\n\
all of this happening still..."))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_POST_PATCH_FOUND_3, 1, 4, 30, 200, _("\
@7F60B4FFOh, are you bored?\n\
I know where a bunch of fun games are\n\
that we could play!\n\
It's been so long since I've played one!\n\
@7F60B4FFAh... but they're elsewhere in the workshop.\n\
Sorry, I forgot we were locked in here...\n\
\n\
"))

DEFINE_DIALOG(DIALOG_SEWNIA_ENOUGH_STARS_HUB_1, 1, 3, 30, 200, _("\
@7F60B4FFHey, good job!!!\n\
I think... I think this is enough!\n\
We might be able to break the seal now!\n\
@7F60B4FFI can't thank you enough, Mario!\n\
Now we can try and find the Threads of Life\n\
to save your friends!"))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_10_STARS_1, 1, 3, 30, 200, _("\
@7F60B4FFAre you nervous?\n\
I won't lie, I am too.\n\
I've kind of liked being trapped in here a bit.\n\
@7F60B4FFIt is quite unfortunate, don't get me wrong,\n\
but there's a comforting sense of safety here...\n\
I feel like opening the door might end that.\n\
@7F60B4FFAh! I don't mean we shouldn't though!\n\
We have to save your friends no matter what!\n\
Open that door whenever you're ready!"))

DEFINE_DIALOG(DIALOG_SEWNIA_FLAVOR_10_STARS_2, 1, 3, 30, 200, _("\
@7F60B4FFThe rest of the workshop beyond the door\n\
really is something, you know.\n\
It's not all musty and old like it is here.\n\
@7F60B4FFSome of the parts are really, really cool!\n\
But... some of them are a little scary, too.\n\
Like the section after this door..."))

DEFINE_DIALOG(DIALOG_SEWNIA_ENTERING_WORKSHOP_1, 1, 3, 30, 200, _("\
@7F60B4FFIt's open...\n\
Alright, here we go...\n\
Beyond that door somewhere is The Patchmaker.\n\
@7F60B4FFHe, uh... might get angry if he sees me.\n\
I think it's best if you go ahead of me, and\n\
I'll trail you from afar..."))

DEFINE_DIALOG(DIALOG_SEWNIA_POST_PATCHMAKER_FIGHT_1, 1, 3, 30, 200, _("\
@7F60B4FFUm...\n\
I'm sorry he attacked you...\n\
I was hoping we wouldn't have a run-in.\n\
@7F60B4FFI guess you have an idea of the state of him...\n\
It might be hard to believe, but he was once a\n\
caring man... I hate seeing him like this.\n\
@7F60B4FFIt just kind of... started happening over time.\n\
He became obsessed with creating something specific.\n\
He wanted to create life again.\n\
@7F60B4FFI'm not sure how I came to be exactly, but The Patchmaker\n\
admitted I was a complete accident. He didn't know how he\n\
created me, but he wanted it again, and became mad over it.\n\
@7F60B4FFAh! Sorry, I didn't mean to ramble.\n\
By the time I caught up, you were already fighting,\n\
but look at this!\n\
@7F60B4FFI think this is the Thread of Life for that\n\
turtle guy! We can revive him!\n\
Let's hurry and...\n\
@7F60B4FF...What? Evil Koopa King?\n\
You make him sound... scary.\n\
But also, really powerful!\n\
@7F60B4FFDo you think we can explain to him\n\
what's going on? Do you think he'll\n\
help us?\n\
@7F60B4FFIt's up to you...\n\
\n\
\n\
@7F60B4FF...\n\
\n\
\n\
@7F60B4FFAlright then, let's go!\n\
Come on, Mario!\n\
"))

DEFINE_DIALOG(DIALOG_SEWNIA_TTC, 1, 3, 30, 200, _("\
@7F60B4FFAh, this pot is a portal to a land\n\
called Thorn Thicket Cliffs!\n\
The smell of roses is always wafting up from within!\n\
@7F60B4FFDon't tell anyone, but I've actually peeked in\n\
there a few times. I was too scared to explore, but there was\n\
a friendly person called a Rosedrift there.\n\
@7F60B4FFShe, um, attempted to say hi to me, but ah...\n\
I was a little nervous, so I came back here.\n\
I'm sure you'll be able to talk better, Mario.\n\
@7F60B4FFRight, anyways. Watch out for the thorny ground there!\n\
The Patchmaker had a special tool when he explored which let him\n\
bypass thorns, so if you haven't found it yet, keep an eye out!\n\
@7F60B4FFWhen he was giving hints on where he hid it, he may have\n\
underestimated my ability to figure it out a little...\n\
I believe it's hidden down a secret path near the top of the cliffs!"))

DEFINE_DIALOG(DIALOG_SEWNIA_RDR, 1, 4, 30, 200, _("\
@7F60B4FFEvery time I opened this door, I could always\n\
hear the distant pitter-patter of raindrops... Sometimes\n\
I would sit here for hours just listening, smelling\n\
the damp musk carried on the cool, wet breeze blowing in.\n\
@7F60B4FFThis door leads to a place called Rainy Day Roadside.\n\
Despite what you may think, it isn't actually right outside.\n\
At some point, you'll pass through a magical portal to the\n\
muddy farmland that lies along a road.\n\
@7F60B4FFI haven't been to any other places, so I can only \n\
tell you what The Patchmaker has told me about this place.\n\
Apparently, there's a rushing river that will sweep you away\n\
if you aren't careful navigating around it.\n\
@7F60B4FFBut if you're brave enough to cross it, there's a hidden\n\
cave along its side. In there, you'll find a patch that will ease\n\
your worries about falling into the river!"))

DEFINE_DIALOG(DIALOG_SEWNIA_STC, 1, 4, 30, 200, _("\
@7F60B4FFI haven't ever opened this door...\n\
After seeing the way it closes, I always got scared of being\n\
caught in between the doors and squeezed between them until I\n\
popped into a pile of stuffing...\n\
@7F60B4FFAh! Sorry! I shouldn't have said that!\n\
I watched The Patchmaker enter here many times, it's perfectly\n\
safe as long as you wait to close it until you're inside!\n\
I'm only being a little scared for no reason here...\n\
@7F60B4FFAnyways, the mechanical clicks of gears echo even with\n\
the doors closed. This door leads to an ancient land called\n\
Stone Terrace City. I've heard it's truly a marvel of technology.\n\
Be careful not to fall off of the moving parts!\n\
@7F60B4FFAs for the patch, I was given the hint that it was\n\
hidden somewhere over a fence... I know that isn't very helpful,\n\
but if you see some fence that looks as though it was climbed over,\n\
I would give it a look!"))

DEFINE_DIALOG(DIALOG_SEWNIA_GSS, 1, 4, 30, 200, _("\
@7F60B4FFThe light in this window only shines when\n\
one of great power stands before it... \n\
So it seems that for you, that would mean star power.\n\
\n\
@7F60B4FFI'll admit, I don't know much about this place.\n\
The Patchmaker described it as a sky stained with a \n\
rich gold, so I suppose it could be called\n\
Gold Soaked Sky...\n\
@7F60B4FFThere are some scary things there. One time, the Patchmaker\n\
returned from it bloodied and beaten. He never told me\n\
what happened, only something about a divine being...\n\
\n\
@7F60B4FFBe very careful if you enter here, Mario. You'll want to find\n\
the patch that was made for this location for sure. I believe\n\
it was hidden somewhere in a vast, empty field."))

DEFINE_DIALOG(DIALOG_SEWNIA_SS, 1, 4, 30, 200, _("\
@7F60B4FFHeehee... This bubble column is a bit different!\n\
That's because it's a portal! It'll suck you down into\n\
cavernous depths surrounded by the salty sea.\n\
@7F60B4FFThe place it goes to is called Subterranean Seaway.\n\
You'll find out that there isn't much to explore without\n\
plunging into the watery depths...\n\
@7F60B4FFBut don't do it until you find the patch that\n\
was hidden there! The Patchmaker said that there's\n\
a strong upward current that prevents anyone but the \n\
strongest swimmer from exploring deeper.\n\
@7F60B4FFSo I think that the patch is hidden somewhere dry...\n\
In any case, be careful as always. I can't imagine\n\
how scary it would be to drown under the sea, with\n\
nobody to hear you...\n\
@7F60B4FF...Be careful, Mario."))

DEFINE_DIALOG(DIALOG_SEWNIA_CLC, 1, 3, 30, 200, _("\
@7F60B4FFThere's something hidden here... One of the portals.\n\
Truthfully, there was once a portal that was out in the open\n\
like the others. It went to a place called Candlelit Chamber.\n\
@7F60B4FFThis place was a little special to The Patchmaker.\n\
Within it, the Master and Mistress of the place were very\n\
good friends of his. Apparently, they visited here to see his works often.\n\
@7F60B4FFAfter he... lost himself... The Patchmaker visited there\n\
once again. I don't know what happened, but I watched from a distance\n\
as he moved the warp tile to another room, looking tired and beaten up.\n\
@7F60B4FFI... didn't want to ask why, but it almost looked like guilt was painted\n\
on his face. It made me want to believe that he wasn't completely\n\
lost yet, but at the same time... What could he have done?\n\
@7F60B4FFSorry... Anyways, if you find the warp in here, watch out.\n\
The manor had a notorious problem with ghost infestations.\n\
It also has many secrets hidden high up above..."))

DEFINE_DIALOG(DIALOG_SEWNIA_HVH, 1, 4, 30, 200, _("\
@7F60B4FFMario, what do you think is defined as real?\n\
I'm sure that line is a little blurred for you with the places you've been...\n\
The Patchmaker talked often about defining reality with words, but\n\
always came to the conclusion that it was not possible.\n\
@7F60B4FFI think this book was the reason why.\n\
When powered up, it seems to be a warp to somewhere far away, but\n\
the people and land there are almost identical to what the book describes.\n\
It's possible that it could be an entire world contained within the book.\n\
@7F60B4FFHe wondered how real it ever was, and if it had the\n\
secrets to the creation of life... But he found that even if it was a\n\
fabricated world, in the end it wasn't any different from everything outside of it.\n\
If people could enter and exit, then how was it any different from reality?\n\
@7F60B4FFSomething you might want to know is that the author was\n\
mysterious. He finished the book on his deathbed, minutes before he passed.\n\
Apparently, this meant that some ends were left untied, and for the\n\
world inside, something about it may not quite fit in...\n\
@7F60B4FFThis place was titled Hidden Village Hold, and it's a very\n\
charming village from what I've read of the book.\n\
As for the patch, it HAS to be in the big wizard tower!\n\
There's no way anything magical wouldn't be in there!"))

DEFINE_DIALOG(DIALOG_SEWNIA_VTW, 1, 3, 30, 200, _("\
@7F60B4FFIt's a beautiful mobile, is it not?\n\
Standing atop it with enough star power will transport\n\
you to a place called Violet Twilit Woods.\n\
@7F60B4FFWhen this was first made, I spent hours looking at\n\
it while waiting for The Patchmaker to return.\n\
That night, I had a very strange dream...\n\
@7F60B4FFI was walking amidst a purple forest, a summer breeze in my hair...\n\
The sound of crickets were a percussion to the melody of the wind,\n\
and as I explored, a slight floral scent was present in the haze.\n\
@7F60B4FFIt was quiet and had a sense of peace I have never felt since...\n\
I don't remember how I got there, but walking amidst the foliage felt like\n\
I was floating, almost as naturally as if I had a pair of wings on my back.\n\
@7F60B4FFI... don't know why, but there was a place I had wanted to find.\n\
I had this idea in my head of a moonlit grove, one that I could lie in\n\
and bask in the filtered light amid a pile of moss.\n\
@7F60B4FFI still wonder if I was truly dreaming...\n\
\n\
\n\
@7F60B4FFAh... Look at me rambling again. Sorry, I should be helping you here...\n\
Although, I can't tell you much to be honest. The Patchmaker stopped\n\
telling me about his journeys around this point...\n\
@7F60B4FF...I really wish things had turned out different.\n\
I never did find that grove, by the way.\n\
And as much as I wish I could, I don't think it's possible anymore."))

DEFINE_DIALOG(DIALOG_SEWNIA_TFP, 1, 3, 30, 200, _("\
@7F60B4FFThis place... The Far Plane...\n\
The Patchmaker... obviously had been changing over time,\n\
but he was never the same after coming back from this place.\n\
@7F60B4FFHe spent weeks in there. I know it seems foolish now, but I was really\n\
scared he had disappeared forever. He didn't even return to create a\n\
patch to navigate it. He did it all in there.\n\
@7F60B4FFI wonder if it was because he got lost...\n\
He was forced to create something that would help him find his\n\
way back from anywhere is all I know...\n\
@7F60B4FFWhen... When he finally got back, he barely talked about it.\n\
I think... I think that this place pushed his madness forward more.\n\
Mario... If you're really going in there, please come back soon...\n\
@7F60B4FFI'm sorry, but that's all I can say...\n\
In truth, I know nothing of this place other than the\n\
fact that it rests close to the edge of existence itself..."))

DEFINE_DIALOG(DIALOG_SEWNIA_EA, 1, 4, 30, 200, _("\
@7F60B4FFHaha...\n\
Oh, sorry. I was just thinking a little about how foolish I was.\n\
I should have known what was happening to The Patchmaker at this point...\n\
How could I have hid in denial with what he made after he went here, after all.\n\
@7F60B4FFSee the covered painting over there? He painted it after coming back here.\n\
The whole time, I hid and watched as he vigorously scratched on the canvas,\n\
a horrid malice in his eyes that conveyed frustration ink could not.\n\
It... scared me, so I covered the painting up after he left.\n\
@7F60B4FFIf... If you think it would help to see the painting, I won't stop you\n\
from peeking... After he finished, The Patchmaker tried talking to me,\n\
assuring me he would create a sister for me. He told me not to worry with a smile,\n\
but this smile hit piles of wrath and weariness for his failures thus far.\n\
@7F60B4FFI think that this was the first time I felt fear in my life.\n\
I didn't know what to tell this breaking man, so I simply nodded in fright.\n\
That was a mistake. I should have never done that.\n\
I...\n\
@7F60B4FFI should have stopped him! I could have! It wasn't too late!\n\
I didn't want a sister, I didn't want him to go to another land!\n\
I just... I just wanted him to stay with me! But I couldn't say anything!\n\
And look what happened! He's... never... coming back...\n\
@7F60B4FFWhy didn't I do anything? Why...\n\
I... I could have...\n\
I could have done it...\n\
\n\
@7F60B4FF...\n\
\n\
\n\
\n\
@7F60B4FFMario... be careful if you're going.\n\
I don't want to lose you too...\n\
I won't let it happen again."))

DEFINE_DIALOG(DIALOG_SEWNIA_CORR, 1, 4, 30, 200, _("\
@7F60B4FFThis place...\n\
After The Patchmaker came back from the last journey hopeless and defeated,\n\
I could tell that he had almost given up on everything.\n\
When he opened the portal, I knew it would not help him find any secrets of life.\n\
@7F60B4FFThis place is a city in a far away land.\n\
One day, a snowstorm blew in and never ceased. The people living there\n\
were quite concerned, as they were right to be when the snow piled up.\n\
Eventually, their doors were covered. And so, they took to higher lands.\n\
@7F60B4FFBut the snow kept coming down. Eventually, even these places were uninhabitable.\n\
So, the people started building. If they couldn't live on the ground, they would on the snow.\n\
After all, the skies would have to clear one day, right?\n\
That's what they thought... But they never did.\n\
@7F60B4FFIt's a land that is constantly being rebuilt and torn down.\n\
And even though it can't be stopped, the people there still rebuild.\n\
It sounds really sad, doesn't it?\n\
That's what I thought at least.\n\
@7F60B4FFThe Patchmaker simply looked forward with a sullen face as he walked into the\n\
fog ahead, and I knew that he had gone there to give up.\n\
But... To my surprise, he returned. He returned with a small glint of hope\n\
in his dead eyes.\n\
@7F60B4FFSomething about this place had resonated with him.\n\
I don't quite understand how, but he picked himself up and\n\
continued his search.\n\
To get something like that from such a hopeless place..."))

DEFINE_DIALOG(DIALOG_SEWNIA_TS, 1, 3, 30, 200, _("\
@7F60B4FFAnd so here it is...\n\
This is where The Patchmaker's journey ended...\n\
And where his madness truly began.\n\
@7F60B4FFInside of this portal is the place where he found the lockbox.\n\
The one that has a pocket between life and death hidden within, where\n\
he hides now...\n\
@7F60B4FFAs for the place itself, you should look for a key to the\n\
lockbox within. I have no idea what you'll be facing, or what The\n\
Patchmaker did to traverse it...\n\
@7F60B4FFBut I believe in you, Mario.\n\
I know you'll see this through, so we can put him to rest.\n\
Just... as always, be careful..."))

DEFINE_DIALOG(DIALOG_SEWNIA_WORKSHOP_HUB_1, 1, 3, 30, 200, _("\
@7F60B4FFOh, you want to know about this part of the workshop?\n\
Well, as somebody who explored this place through and through,\n\
I'd be glad to tell you!\n\
@7F60B4FFSo, this part is actually pretty old and forgotten, even\n\
more so than most areas here. It was the very first part of the workshop\n\
that was built, after all. It has a slight nostalgic feeling...\n\
@7F60B4FFThe Patchmaker used magic to build a lot of the workshop, but\n\
this area was all built by hand.\n\
It's sure showing its neglect, huh?\n\
@7F60B4FFUm... what else...\n\
Oh! The window in the attic! It might seem dull and dark,\n\
but I would check on it when you get a decent amount of star power!"))

DEFINE_DIALOG(DIALOG_SEWNIA_WORKSHOP_HUB_2, 1, 5, 30, 200, _("\
@7F60B4FFThis part of the workshop could be better \n\
described as a museum. The Patchmaker displays \n\
a lot of his work here, and he even\n\
went out of his way to make the stairs \n\
themselves artistic and whimsical.\n\
@7F60B4FFSee, he wanted to one day open up a gallery \n\
to the public. This place is quite off the beaten \n\
path in terms of location, but he\n\
claimed that those seeking art will \n\
always look hard for it.\n\
@7F60B4FFIt was a lofty dream... But I had always\n\
believed he could do it. That was so long ago...\n\
\n\
\n\
...I hope the dream can still be real one day."))

DEFINE_DIALOG(DIALOG_SEWNIA_WORKSHOP_HUB_3, 1, 3, 30, 200, _("\
@7F60B4FFThis... is where The Patchmaker had spent most of his\n\
time before everything recent happened.\n\
I have bad memories of this place...\n\
@7F60B4FFI'm sure you can tell by everything around you just how obsessed he became.\n\
I really had hoped to not be coming back here, but...\n\
Um... Something is missing. Something that was here before.\n\
@7F60B4FF...Huh? You asked what it was?\n\
I... I don't want to say. It isn't important.\n\
I just wonder where they all went..."))

DEFINE_DIALOG(DIALOG_SEWNIA_EA_ALTERNATE, 1, 3, 30, 200, _("\
@7F60B4FFI... don't want to talk about this place again\n\
if that's alright...\n\
Sorry..."))

DEFINE_DIALOG(DIALOG_SEWNIA_STOP_FOLLOWING, 1, 3, 30, 200, _("\
@7F60B4FFOh, you want me to stop following you?\n\
Of course, I'll be around if you\n\
need me."))

DEFINE_DIALOG(DIALOG_SEWNIA_STOP_FOLLOWING_BOWSER, 1, 3, 30, 200, _("\
@7F60B4FFGot it, I'll go see what\n\
Mr. Bowser is up to! He'll probably\n\
like the company, even if he doesn't say it!"))

DEFINE_DIALOG(DIALOG_SEWNIA_STOP_FOLLOWING_PEACH, 1, 4, 30, 200, _("\
@7F60B4FFAlright then, good luck!\n\
I'll think I'll go talk with Princess Peach!\n\
It seems like she has a lot to teach me,\n\
especially the lady-like stuff!"))

DEFINE_DIALOG(DIALOG_SEWNIA_START_FOLLOWING, 1, 3, 30, 200, _("\
@7F60B4FFAh! Well then, lead the way!\n\
\n\
"))




DEFINE_DIALOG(DIALOG_BOWSER_REVIVED, 1, 3, 30, 200, _("\
@7F60B4FFIs he awake?\n\
\n\
\n\
@FF0202FFUrk...\n\
What the...\n\
\n\
@FF0202FFWhere am I?\n\
\n\
\n\
@FF0202FFHey! What on earth is Mario doing here!?\n\
I HATE seeing him when I wake up!\n\
...It usually means I lost a fight!\n\
@7F60B4FFAre you... Bowser?\n\
Mario told me a bit about you!\n\
\n\
@FF0202FFUh... who's the freaky doll?\n\
Hrgh... My head...\n\
\n\
@7F60B4FFMy name is Sewnia!\n\
Bowser, you were brought here by a man\n\
known as The Patchmaker, and he-\n\
@FF0202FFHey, I remember now! I was performing my awesome\n\
attack on Mushroom Castle! It was going great, until that\n\
weirdo man showed up!\n\
@FF0202FFI watched him turn Mario into a doll right before my eyes!\n\
He jumped out while I was storming the castle for Peach,\n\
while Mario was blocking me, and attacked from behind!\n\
@FF0202FFAfter that... he must have gotten me too!\n\
Bwaaargh! No!!! I can stomach losing to Mario,\n\
but I won't accept losing to ANOTHER human!\n\
@FF0202FFI'm gonna beat the daylights outta that guy!\n\
Where is he!?\n\
\n\
@7F60B4FFBowser, wait! He probably sealed himself off in\n\
another section of the workshop to hide if I had to guess.\n\
Plus, it's dangerous!\n\
@FF0202FFSorry girlie, I need to get revenge on this jerk!\n\
I don't lose to random guys!\n\
So now I think I'll... Huh?\n\
@FF0202FFWhat happened to...\n\
Is that...?\n\
\n\
@FF0202FFDid he do this to Peach, too!?\n\
I'LL... I'LL...! I'LL GIVE THE FLOOR A NEW\n\
COAT OF WAX WITH HIS FACE! GRRAAGHHH!!!\n\
@7F60B4FFBowser! Please calm down! We can still save her!\n\
We need to focus on exploring as much of the workshop as\n\
we can! Maybe her Thread of Life is around somewhere!\n\
@FF0202FFThen what are we waiting for? MOVE!\n\
Mario, doll girl! What are you doing just waiting here?\n\
Peach needs me, let's GO!!!"))

DEFINE_DIALOG(DIALOG_ENTER_SECOND_HUB_1, 1, 3, 30, 200, _("\
@7F60B4FFHere we are...\n\
\n\
"))

DEFINE_DIALOG(DIALOG_ENTER_SECOND_HUB_2, 1, 3, 30, 200, _("\
@7F60B4FFLet's look around for Princess Peach's\n\
Thread of Life. But... I have a feeling it might\n\
not be here. This place is kept clean without clutter.\n\
@FF0202FFHey! Anything with Peach's name on it IS\n\
clean! Very clean! And it probably smells like\n\
flowers, too!\n\
@7F60B4FFHehe... You seem scary Bowser, but\n\
you're actually pretty silly!\n\
\n\
@FF0202FFI AM SCARY! Don't get on my wrong side.\n\
Just because you're not Mario doesn't mean I wanted\n\
to team up with you! I'm here for Peach!\n\
@7F60B4FFRight... Assuming we can't find her thread,\n\
Mario will be able to explore more portals to lands\n\
even farther out than the last ones here...\n\
@7F60B4FFWe'll need it, too. I'm sure a more powerful\n\
magical barrier is waiting for us through the only\n\
way through... Nothing star power can't break!\n\
@FF0202FFWell, Mario can go on his dumb adventure\n\
or whatever, but I'm going to be turning over every\n\
stone to find Peach's thread!\n\
@FF0202FFI mean, do you know how small those things are!?\n\
It could be between the floorboards for all we know!\n\
I'll save you, Peach! I promise!\n\
@7F60B4FFMario, I'll do my best to tell you everything\n\
I know about the areas here. Make sure to ask\n\
me if you want to know more!"))

DEFINE_DIALOG(DIALOG_PATCHMAKER_MEET_MARIO, 0b10, 3, 30, 200, _("\
@5D5D5DFFHmm?\n\
\n\
\n\
@5D5D5DFFYou... Red one. Why do you move?\n\
\n\
\n\
@5D5D5DFFI thought that I had dealt with you.\n\
DEALT WITH you... Ahaha...\n\
Moving? You're moving?\n\
@5D5D5DFFNo... You aren't supposed to!\n\
I need you to stop that...\n\
STOP THAT! AHAHA! STOP IT!\n\
@5D5D5DFFYou were another failure. The failures need...\n\
They need to be put into the box!\n\
Too many! Haha...\n\
@5D5D5DFFTHE FAILURES THAT MOVE!\n\
THEY GO... They go into the box!\n\
Ahaha...\n\
@5D5D5DFFRed one... You mustn't move!\n\
If you do... I have failed again!\n\
Ahahaha!\n\
@5D5D5DFFNow... TIME TO BE STILL!"))

DEFINE_DIALOG(DIALOG_VILLAGER_FRUIT, 1, 3, 30, 200, _("\
Fresh fruit!\n\
Get it here!\n\
\n\
You, in the red!\n\
Care for some fresh fruit?\n\
No? What a shame!"))

DEFINE_DIALOG(DIALOG_VILLAGER_FLOWERS, 1, 3, 30, 200, _("\
Some rascal took my red flowers and hid them\n\
all over town!\n\
Argh!!!\n\
These aren't ordinary flowers, either!\n\
They hold the secret to making some\n\
good coin! Ahh, I miss my red coin flowers!"))

DEFINE_DIALOG(DIALOG_VILLAGER_FAR_AWAY, 1, 3, 30, 200, _("\
Yeesh, I can tell you're not from around here.\n\
Here's a tip from a local.\n\
\n\
Ever since those jerks occupied that castle,\n\
the monster problem around town has gotten pretty bad.\n\
I'd watch out, and expect the unexpected!"))

DEFINE_DIALOG(DIALOG_VILLAGER_TRAVELERS, 1, 3, 30, 200, _("\
Well, hi there!\n\
We don't get too many travelers around here.\n\
Welcome to our village!\n\
I must say, the people visiting are quite strange.\n\
First it was that @FF0000FFtall man in a tailcoat suit@FFFFFFFF,\n\
and now you're here too.\n\
There's also some guy in a hood hanging around town.\n\
I'm not sure what his deal is, but he seems\n\
a little scary to me..."))

DEFINE_DIALOG(DIALOG_VILLAGER_SILO, 1, 3, 30, 200, _("\
Oh, blast it all!\n\
Somebody keeps leaving that darn silo open!\n\
We built the hatch up there for a REASON!\n\
I swear, if I get up there and there's\n\
a buncha dirt tracked over our harvest..."))

DEFINE_DIALOG(DIALOG_VILLAGER_STRONGNUT_FAN, 1, 3, 30, 200, _("\
Teehee!\n\
See that guy over there? His name is Strongnut.\n\
He's REALLY popular with all the ladies in town!\n\
I hear he stands there all day, waiting for somebody\n\
strong enough to knock him over. How manly!\n\
Still, he's dumb as bricks. Our flirting flies right over him."))

DEFINE_DIALOG(DIALOG_STRONGNUT_1, 1, 3, 30, 200, _("\
Bwahaha!\n\
What are yeh, a man, or a mouse?\n\
Grow some muscle, yeh wee shrimp!"))

DEFINE_DIALOG(DIALOG_STRONGNUT_2, 1, 3, 30, 200, _("\
Pathetic!\n\
Me wee lil' niece could throw a better\n\
blow 'an that!"))

DEFINE_DIALOG(DIALOG_STRONGNUT_3, 1, 3, 30, 200, _("\
Did I just feel a breeze?\n\
Oh! Me bad! It 'as only this lil'\n\
bug dat flew past! Hahaha!"))

DEFINE_DIALOG(DIALOG_STRONGNUT_BEATEN, 1, 3, 30, 200, _("\
URK!!!\n\
Is... is it finally o'er?\n\
Has big Strongnut finally taken 'is fall?\n\
And by a puny lil' runt no less...\n\
Hurgh... That blow didn't lie though...\n\
I'll give yeh this shiny thing as a prize."))

DEFINE_DIALOG(DIALOG_SOLIDS_HALT, 1, 3, 30, 200, _("\
@7DAFFFFFHALT!!!"))

DEFINE_DIALOG(DIALOG_SOLIDS_PRE_FIGHT, 1, 3, 30, 200, _("\
@7DAFFFFFWHAT IS THE MEANING OF THIS?\n\
A CREATURE SUCH AS YOU SHOULD NOT ENTER HERE.\n\
THIS HOLD IS ONLY FOR THOSE OF PERFECT FORM.\n\
@7DAFFFFFWE WILL DISCARD ALL THAT IS NOT PERFECT.\n\
THE VILLAGERS, THIS WORLD, THE LAND WE\n\
HAIL FROM... IT IS ALL IMPERFECT.\n\
@7DAFFFFFNO, WE FIVE ARE THE ONLY PERFECT SHAPES.\n\
THE ONLY PERFECT BEINGS IN THIS\n\
DISGUSTING, SMOOTH WORLD.\n\
@7DAFFFFFPERFECT! PERFECT! PERFECT!\n\
OUR FORMS ARE... PERFECT!\n\
AND YOU WON'T TRY AND CHANGE THEM!"))

DEFINE_DIALOG(DIALOG_MASTER_WELCOME, 1, 3, 30, 200, _("\
Welcome, mister Mario.\n\
I express gratitude that you came all\n\
the way up here to see me.\n\
Please have a seat.\n\
There is much to discuss.\n\
"))

DEFINE_DIALOG(DIALOG_MASTER_STORY, 1, 4, 30, 200, _("\
I apologize for the lack of hospitality.\n\
As I'm sure you know by now, this manor is\n\
not in a good state. It all stems\n\
from the disease permeating the area.\n\
The plague that corrupts the spectral\n\
servants is one of magic and madness.\n\
Worry not, us living beings are unaffected\n\
by it. But as for it's root...\n\
Well, I'm sure you know by now. The man\n\
you know as The Patchmaker is the cause.\n\
Truthfully, he was once a friend of mine...\n\
That man had ambitions beyond our wildest dreams.\n\
Though it was a far trip, I often visited him\n\
to view his latest works, which ranged from\n\
simple sculptures, to magnificent mechanical marvels.\n\
One day, he was the one to visit me.\n\
He told me about his greatest creation yet,\n\
a living doll. Though he loved and cherished her,\n\
he could not help but wish to recreate the miracle\n\
of her existence. Such is a creator's desire.\n\
He asked me to allow him to study my servants.\n\
To recreate this miracle, he needed more knowledge\n\
about life itself, and spirits were something that\n\
he thought could give him a lead.\n\
I allowed him, and he spent days studying them,\n\
their behaviors, their connection to this world.\n\
What he found was that the ghosts we see are not\n\
the ones he sought out.\n\
These spirits have purpose, tangibility.\n\
They were placed in this world for a reason,\n\
to exist in the shape and soul that they\n\
do. I tried to explain this to him.\n\
He was not deterred, and insisted that there\n\
was a way to give spirits new life. After all,\n\
there is no life without a soul. His living\n\
doll was alive, with feelings and emotions...\n\
At this point, signs of his desperation were showing.\n\
He asked me to let him experiment on a servant next,\n\
an outrageous proposition that I immediately denied.\n\
Perhaps I shouldn't have, but I chastised him for asking.\n\
The Patchmaker stormed off after that. And the next time\n\
I saw him, a year later... \n\
He was not the man I formerly knew.\n\
\n\
It started with one of the Phantasmaids going missing.\n\
We searched for her, until we saw a horrifying sight.\n\
The Patchmaker stood over the missing servant with a vial,\n\
as she writhed and contorted into a Blight.\n\
We had naught but a moment to be surprised before the Blight\n\
went berserk and attacked us. The Patchmaker fled as the\n\
servants beside me began to contract the effects of\n\
the experiment that he had performed.\n\
As I ran, I became worried about my wife.\n\
She had been searching with us as well, but with the\n\
maniacal Patchmaker on the loose, I feared the worst.\n\
While I ran, I ordered everyone to lock up the doors.\n\
When I finally found her, what I saw horrified me.\n\
A large needle stuck into the flesh of her face was\n\
weaving thread through it with unsettling fluidity.\n\
The kind of craftwork that happens with thousands of tries.\n\
All the while, the man controlling the needle smiled\n\
softly, the face behind it focusing on the weaving and\n\
winding of thread, smiling despite my wife's \n\
blood-curdling screams of terror, just... Smiling.\n\
This man that stood in front of me knew no morality.\n\
All he knew was his craft, the motions of creation.\n\
All of these thoughts coalesced in my mind as I stood\n\
in abject horror at what he was doing.\n\
Perhaps it was the last shreds of his former self, or\n\
it may have merely been my interruption of his work,\n\
but when he saw me he stopped.\n\
He gently set down the needle and walked away.\n\
That was the last I ever saw of him.\n\
I later learned that he had done this\n\
to many creatures before, turning them into\n\
craftwork without a mind of their own.\n\
To do such a thing to a friend...\n\
There is no doubt that The Patchmaker has\n\
completely lost his former self.\n\
As for how, who knows...\n\
And then, there is my poor wife. While she is\n\
better off than most of the other beings that\n\
The Patchmaker experimented on, she can hardly\n\
think anymore. She is in a state of constant suffering.\n\
I can hardly look at her anymore without the horrid\n\
memories of that day paralyzing me.\n\
And thus, I have kept to my study for the\n\
future. This manor will likely never be the same.\n\
Mario... I know not what you have planned to\n\
confront The Patchmaker. However, I must tell you\n\
this: that man is beyond saving. He is nothing\n\
but a walking husk without morals.\n\
Keep this in mind so that something terrible\n\
does not occur.\n\
Now then, that is all I have to tell you.\n\
I do apologize for keeping you so long.\n\
Mister Mario, we have utmost faith in you.\n\
The future of all of us here hangs in the\n\
balance. Take this. I was keeping it as a\n\
failsafe, but you'll need all the help you can get."))

DEFINE_DIALOG(DIALOG_BEFORE_REVIVE_PEACH, 1, 4, 30, 200, _("\
@7F60B4FFHey, Bowser...\n\
You're not holding it straight again...\n\
\n\
\n\
@FF0202FFWhy you little...!\n\
I definitely AM holding...\n\
Oh...\n\
Sorry, is this better?\n\
@7F60B4FFYes... Thank you, Bowser.\n\
Mario... make sure you keep my\n\
arms straight, alright?\n\
\n\
@7F60B4FFThis is already hard enough...\n\
\n\
\n\
\n\
@FF0202FF...Does it hurt?\n\
That was absolutely ruthless...\n\
I wish I had woke up faster.\n\
\n\
@7F60B4FFIt's alright... I'm just glad you're ok.\n\
And no... It doesn't hurt at all.\n\
To be honest, it's a miracle I can still\n\
move...\n\
@7F60B4FFAh! I think... I think I've got it!"))

DEFINE_DIALOG(DIALOG_PEACH_REVIVED_1, 1, 4, 30, 200, _("\
@FF75DFFFNgh...\n\
My head...\n\
Where... am I?\n\
\n\
@FF0202FFPrincess Peach!\n\
You're okay!\n\
\n\
\n\
@FF75DFFFBowser!? Mario, too?\n\
What on earth is going on here?\n\
\n\
\n\
@7F60B4FFYou're Princess Peach?\n\
These two have said a lot of nice things\n\
about you...\n\
Hi... I'm Sewnia.\n\
@FF75DFFFAww! What a cute little doll!\n\
What happened to you, though?\n\
Wait just a minute...\n\
\n\
@7F60B4FFUm...\n\
That's not important right now...\n\
I have to tell you what's-\n\
...Huh?\n\
@FF75DFFFSorry, dear... I couldn't bear to see you\n\
ripped up like that. I'll fix you\n\
right up!\n\
\n\
@FF0202FFBwahaha! That's the princess for you!\n\
She'd help just about anyone, even people\n\
she doesn't know!\n\
\n\
@7F60B4FFTh... Thank you.\n\
I'll try and explain everything as\n\
best as I can...\n\
"))

DEFINE_DIALOG(DIALOG_PEACH_REVIVED_2, 1, 4, 30, 200, _("\
@7F60B4FF...And that's about it.\n\
After we got your Thread of Life back,\n\
we came straight here to revive you...\n\
...Oh! You... you fixed me! Thank you!\n\
@FF75DFFFI'm glad you're feeling better, Sewnia.\n\
Your head should be on straight again!\n\
And now...\n\
\n\
@FF75DFFF...You've been through a lot, haven't you?\n\
I could tell during your story.\n\
It's all okay now...\n\
\n\
@7F60B4FFPrincess Peach, I...\n\
I um...\n\
\n\
\n\
@7F60B4FF...\n\
\n\
\n\
"))

DEFINE_DIALOG(DIALOG_PEACH_REVIVED_3, 1, 4, 30, 200, _("\
@7F60B4FFHow... how could he do that to me?\n\
Why would he do that to me?\n\
Does he... does he really hate me that much?\n\
\n\
@FF75DFFFShh... It's not your fault.\n\
You know that. He isn't the man who once\n\
took care of you anymore.\n\
No father would ever do such a thing.\n\
@FF75DFFFI can't believe you two didn't comfort her sooner!\n\
Especially you, Bowser!\n\
As a parent, how could you be so dense to\n\
her suffering!?\n\
@FF0202FFHey! You think I didn't notice!?\n\
There's a REASON I can't stand that Patchmaker guy!\n\
Being a king, a father... A soulless husk like that\n\
who only causes suffering ticks me off!\n\
@7F60B4FFIt's alright, Princess Peach...\n\
I thought I would just get in the way of rescuing\n\
everyone, so I tried my hardest not to be a burden...\n\
But even then... Why did things turn out this way?\n\
@7F60B4FFWhy him? Why did he have to lose himself?\n\
He was all I ever knew, all I ever had...\n\
And now, I... I'm alone...\n\
He's... gone. I have to... accept it.\n\
@7F60B4FFI always held out a slight bit of hope.\n\
That he was able to be saved...\n\
That Mario could do something...\n\
But I see now... That future is tarnished.\n\
@FF75DFFFSewnia... Are you sure about this?\n\
I mean... Even some of the most vile\n\
people I know have good in them.\n\
Maybe, just maybe-\n\
@FF0202FFHrmph! You're wrong.\n\
You haven't met that man. He's far,\n\
far gone. I'm not going to pretend\n\
otherwise. Sorry, doll. It's the truth.\n\
@FF75DFFFBowser!\n\
\n\
\n\
\n\
@7F60B4FFNo... He's right, Princess. Truly.\n\
I can't keep hiding behind hope forever.\n\
Especially... After what he did to me.\n\
My... my father would have never done that.\n\
@7F60B4FFThat's why... I have to ask you, Mario...\n\
No, I'm begging you. Please help me...\n\
I know you were saving your friends, but I can't\n\
let my father keep going on like this.\n\
@7F60B4FFI can't bear to see anyone else hurt by him...\n\
And whatever is left of him is suffering...\n\
Which is why...\n\
We need to find and defeat him.\n\
@FF0202FFBwahaha! Now THAT is a plan, Sewnia!\n\
I'll make this guy pay!\n\
\n\
\n\
@FF75DFFFI agree as well.\n\
If you're truly set on this, we'll\n\
see it through to the end for you!\n\
Even if we have just met.\n\
@7F60B4FFTh... Thank you.\n\
It means so much to me...\n\
Ah...\n\
I feel a lot better now.\n\
@7F60B4FFAlright, there's no time to waste!\n\
Let's finish this, Bowser!\n\
And Peach!\n\
And of course, Mario!"))

DEFINE_DIALOG(DIALOG_PRINCE_INTRO, 1, 3, 30, 200, _("\
@4C2ABDFFYou.\n\
\n\
\n\
@4C2ABDFFI have been watching you.\n\
\n\
\n\
@4C2ABDFFTell me. Do you have knowledge of\n\
where you currently stand?\n\
Do you have purpose in being here?\n\
@4C2ABDFF...And do you know the story\n\
of that cursed patch you found here?\n\
Its true capabilities?\n\
@4C2ABDFFThis realm is the highest point of\n\
the lowest reaches. It reflects on its\n\
perciever much as the inverse is true...\n\
@4C2ABDFFWhat I say is that whether one drowns\n\
or swims here depends on one's state of mind.\n\
And yet... you are an anomaly.\n\
@4C2ABDFFYou neither float nor sink here...\n\
A strong sense of purpose is keeping you\n\
firmly grounded, yet able to move. How peculiar.\n\
@4C2ABDFFHad it not been for this odd behavior, I\n\
would have immediately chased you away...\n\
Especially after recent events.\n\
@4C2ABDFFI can see in your eyes you know what\n\
I am about to say... But a man recently\n\
traveled here in pursuit of eldritch secrets.\n\
@4C2ABDFFHe was already nearing his breaking point,\n\
and this realm is what seemed to have\n\
made his mind cross some line...\n\
@4C2ABDFFWhen he first arrived here, I met him.\n\
I told him plainly, his quest was in vain.\n\
The secrets of life were not his to hold.\n\
@4C2ABDFFLife is an elusive, precious aspect of existence.\n\
To wish to control it, manufacture it...\n\
Such a practice as that shall not be.\n\
@4C2ABDFFAnd when I next saw him...\n\
He was brimming with hatred, that patch\n\
upon his sleeve, radiating malice.\n\
@4C2ABDFFHe attacked me without purpose, without goals,\n\
only to kill. The patch had been made for\n\
my demise particularly.\n\
@4C2ABDFFBut...\n\
You do not possess the same hatred.\n\
I can sense that clearly.\n\
@4C2ABDFFHowever... I need to make sure\n\
you will not succumb to its toxic\n\
hatred that permeates the air around it.\n\
@4C2ABDFFI am able to see both past and future...\n\
You, Mario, will confront this man soon.\n\
When that time comes, will you be in control?\n\
@4C2ABDFFSo... Prove it to me, Mario.\n\
If you can maintain control over a long\n\
fight, the patch is yours to keep.\n\
@4C2ABDFFA useful tool... Or demise.\n\
We shall commence a battle to see which\n\
path you take!"))

DEFINE_DIALOG(DIALOG_PRINCE_DEFEATED, 1, 3, 30, 200, _("\
@4C2ABDFF...Wonderful\n\
\n\
\n\
@4C2ABDFFYou have proven yourself.\n\
In truth, I knew it would turn\n\
out this way...\n\
@4C2ABDFFBut... fate can always bend.\n\
Nothing is predetermined by visions\n\
alone.\n\
@4C2ABDFFYour future will be a good one\n\
so long as you continue this way.\n\
Do not lose sight of what is important.\n\
@4C2ABDFFI shall now aid you on your quest.\n\
Take this as a token of victory."))

DEFINE_DIALOG(DIALOG_BOOK_AUTONOMY, 0b100, 3, 30, 200, _("\
@FEFEFEFFIf one pictures an eye, it can perceive all around it.\n\
The eye chooses what it observes, and thus, has full\n\
autonomy over its actions, its reality.\n\
@FEFEFEFFEyes are complicated structures, not simply able to be\n\
constructed by man in a capacity anywhere near as capable\n\
as the ones we possess.\n\
@FEFEFEFFAnd so, we can do nothing but try to emulate the eye in \n\
what we create. Upon something such as a yarn doll, the eye\n\
is represented by a sewn-on button.\n\
@FEFEFEFFSomething attached in this way has no autonomy. It was\n\
affixed for one intent, and its actions can only be stirred\n\
by an external force.\n\
@FEFEFEFFThus, it can be inferred that the nature of something with a\n\
sewn-on eye is controlled, lacking free will.\n\
\n\
@FEFEFEFFAnd to be alive is to have free will."))

DEFINE_DIALOG(DIALOG_BOOK_DEFINING_LIFE, 0b100, 4, 30, 200, _("\
@FEFEFEFFMan oftentimes wishes to create a concrete foundation of\n\
any term to serve as our understanding of a concept.\n\
In our definition of life, we claim that immobile plants\n\
are of the same ilk as creatures that breathe and move.\n\
@FEFEFEFFIn a basic sense, the similarities between these two things\n\
can be life. However, the life I pursue to create is \n\
different.\n\
\n\
@FEFEFEFFIf my goal were merely to create something humanoid and\n\
with motion, then I had accomplished my goal years ago\n\
with my music box automaton.\n\
\n\
@FEFEFEFFIf I wished life to be something that moves without\n\
machinery, a new state of existence, then I also have\n\
reached that goal with the creatures I have woven over\n\
with yarn.\n\
@FEFEFEFFBut my itch for recreation does not let me deceive\n\
myself. I know what the life I want to create truly is.\n\
All I wish to do is recreate my greatest work, another\n\
living doll.\n\
@FEFEFEFFOne that was a complete mystery as to how life came to be."))

DEFINE_DIALOG(DIALOG_BOOK_MACHINE, 0b100, 3, 30, 200, _("\
@FEFEFEFFI mean not to sound pretentious in my writing...\n\
After all, I intend to one day show the world\n\
my work.\n\
@FEFEFEFFHowever, to create the work in the first place, I must\n\
shun the world itself. Such is the sacrifice of\n\
full commitment and dedication.\n\
@FEFEFEFFThrough learning fine machinery and complicated spells,\n\
through weaving intricate patterns and painting thoughts,\n\
through sculping imagination and making dreams real...\n\
@FEFEFEFF...I have always wondered if by the time I were finished,\n\
the people in the world I had shunned would not be there\n\
to see my work in the end.\n\
@FEFEFEFFWhat is there to achieve if nobody is there to see it?\n\
And yet... time spent with others is time that could be\n\
spent bettering my craft. A paradoxical misfortune.\n\
@FEFEFEFFThese thoughts berate me, they slow me down, they tempt\n\
me with ideas of a life wasted, a life in the dark,\n\
a life without recognition and a death forgotten.\n\
@FEFEFEFFHow is one supposed to create when it comes at such\n\
a cost? Ideas are limitless, but time is the ultimate\n\
boundary, one that even I cannot elude.\n\
@FEFEFEFFTo progress in life would be to create something\n\
that could offer the satisfaction of a lifetime.\n\
Something I have yet to do...\n\
@FEFEFEFFAnd if I were to never achieve such a thing...\n\
Is it my ego or my ambition I must overcome\n\
to truly move on?\n\
@FEFEFEFF...I am a machine.\n\
A well-oiled machine.\n\
"))

DEFINE_DIALOG(DIALOG_BOOK_SEWNIA, 0b100, 3, 30, 200, _("\
@FEFEFEFFOne day, whilst crafting a plush doll,\n\
something miraculous occured.\n\
The doll smiled at me.\n\
@FEFEFEFFI had done nothing different, nor special, and yet,\n\
the doll breathed life. It grew tenfold and\n\
sat upon my work station, looking around curiously.\n\
@FEFEFEFFThat was the day I became part of a family.\n\
That day, Sewnia was born.\n\
\n\
@FEFEFEFFI taught her like she was my own daughter.\n\
Creating life was an incredible feat, and even\n\
more surprising were her capabilities.\n\
@FEFEFEFFShe behaved like a child would, yet\n\
she could speak perfectly, and some words\n\
she knew, not even I had heard before.\n\
@FEFEFEFFI was so morbidly curious about it all.\n\
No magic had ever created life itself. But...\n\
She is a living person, and I will treat her as one.\n\
@FEFEFEFFAll my worries, all my failures and successes...\n\
They led to this. I know it. This is my\n\
life's work, to bring her to life.\n\
@FEFEFEFFAnd yet... There is a nagging pain in the back of my\n\
mind. A small part of me feels as though this feat\n\
is not mine to hold, a mere fluke of chance.\n\
@FEFEFEFFNo... I am finally fulfilled, I have created\n\
something marvelous, and I shall focus on her.\n\
I mustn't let that small feeling grow.\n\
@FEFEFEFFSewnia's joy is my focus now.\n\
I'll do what makes her happy.\n\
I truly will."))

DEFINE_DIALOG(DIALOG_MEMORY_1, 1, 3, 30, 200, _("\
@7E5FB3FFFather, look! Look at what I drew!\n\
There's you, and there's me!\n\
Wonderful, isn't it?\n\
@5C5C5CFFLet me see, dear...\n\
Ah! It is! At this rate, you'll be a great\n\
artist like your old man, Sewnia!\n\
@7E5FB3FFHehehe... I hope so!\n\
What are you working on, father?\n\
\n\
@5C5C5CFFIt's a secret! Your third birthday is\n\
coming up, after all. Though, it feels a bit\n\
odd to say that when you act much older than three...\n\
@7E5FB3FFYay! I can't wait to see what it is!\n\
\n\
\n\
@5C5C5CFFSay, Sewnia... This may seem unrelated, but...\n\
\n\
\n\
@5C5C5CFFWhat would you think about having a sister?\n\
"))

DEFINE_DIALOG(DIALOG_MEMORY_2, 1, 3, 30, 200, _("\
@7E5FB3FFFather... are you leaving again?\n\
You just got back...\n\
\n\
@5C5C5CFFI'm sorry, Sewnia.\n\
I'm so very close to figuring this out.\n\
The secrets of life are closer than ever.\n\
@7E5FB3FFYes... but...\n\
You... just got back.\n\
Aren't you... tired?\n\
@5C5C5CFFYes. I am.\n\
The burning desire to create life\n\
once more is motivation enough, though.\n\
@5C5C5CFFSewnia... you know, I'm doing\n\
this for you, right?\n\
Creating a sister...\n\
@5C5C5CFFIt's what you wanted, right?\n\
\n\
\n\
@7E5FB3FFI...\n\
Um...\n\
...yes. It is...\n\
@5C5C5CFFGood.\n\
I'll be off then.\n\
\n\
@7E5FB3FF...I wish you could\n\
have stayed to play a little with me.\n\
You didn't even see my new drawing...\n\
@7E5FB3FFI'll... show him when he's back.\n\
I'm sure it will make him happy.\n\
He looks so tired lately..."))

DEFINE_DIALOG(DIALOG_MEMORY_3_1, 1, 3, 30, 200, _("\
@5C5C5CFFI've found it, Sewnia.\n\
I've found something that may...\n\
No, it WILL. It will let me make life.\n\
@5C5C5CFFGaze upon this marvelous lockbox.\n\
It took me so long to find this...\n\
But I can finally reach a new magnum opus!\n\
@7E5FB3FFDoes... does that mean you'll\n\
be around again? We can go...\n\
back to how things were?\n\
@5C5C5CFFAnd more! I'll do it, Sewnia.\n\
I'll make you a sister!\n\
And then, we may be happy!"))

DEFINE_DIALOG(DIALOG_MEMORY_3_2, 1, 3, 30, 200, _("\
@5C5C5CFF...Another failure.\n\
Disappointing.\n\
\n\
@5C5C5CFFI'm able to sew a soul to the doll...\n\
but what results is more of a zombie than\n\
a living thing.\n\
@5C5C5CFFWhat could I be missing...?\n\
\n\
\n\
@5C5C5CFFPerhaps it has something to do with\n\
Sewnia's appearance...?\n\
\n\
@5C5C5CFFNo...! What am I saying!?\n\
I couldn't possibly...\n\
I should just try again. I'm nearly there."))

DEFINE_DIALOG(DIALOG_MEMORY_3_3, 1, 3, 30, 200, _("\
@5C5C5CFFDamn it all!\n\
\n\
\n\
@5C5C5CFFIt isn't working!\n\
Not like this, at least!\n\
\n\
@5C5C5CFFI... I didn't...\n\
I didn't do this all for nothing.\n\
I can't have.\n\
@5C5C5CFFI'll try one...\n\
Just one... that looks like her.\n\
After all... it will be her sister..."))

DEFINE_DIALOG(DIALOG_MEMORY_3_4, 1, 3, 30, 200, _("\
@7E5FB3FFFather, I..."))

DEFINE_DIALOG(DIALOG_MEMORY_3_5, 1, 2, 30, 200, _("\
@5C5C5CFF...But a needle thin enough to sew life\n\
itself would never be enough to take my own.\n\
@5C5C5CFFAnd so... through the guilt,\n\
the pain, and the weariness...\n\
I continued my work."))

DEFINE_DIALOG(DIALOG_BOWSER_NPC_ARRIVED_AT_SECOND_HUB, 1, 3, 30, 200, _("\
@FF0202FFThis is the worst...\n\
Peach being in danger is bad enough, but I\n\
have to team up with YOU to save her?\n\
@FF0202FFJust don't get in my way, got it?\n\
Go explore those stupid portals, they're too\n\
small for me to fit into anyways!\n\
@FF0202FFEven better, don't come back!\n\
Then I'll be the one to save Peach, and she'll\n\
finally realize what a BOSS I am! Bwahaha!"))

DEFINE_DIALOG(DIALOG_BOWSER_NPC_AUTOMATON, 1, 3, 30, 200, _("\
@FF0202FFThis room smells like an old grandma.\n\
I bet its that weird looking robot...\n\
moving... lady thing on that giant music box.\n\
@FF0202FF...What? It's called an automaton?\n\
I didn't ask, pasta-brain!\n\
That kind of language makes you a nerd!\n\
@FF0202FFStill, I'll give that Patchmaker guy one thing...\n\
He sure knows how to make a lot of junk.\n\
He didn't even sell any of it! What a loser!"))

DEFINE_DIALOG(DIALOG_BOWSER_NPC_BUBBLES, 1, 3, 30, 200, _("\
@FF0202FFHow is a bunch of bubbles supposed to be art?\n\
This stuff makes no sense to me...\n\
Urgh... I hope Peach's thread isn't in the water..."))

DEFINE_DIALOG(DIALOG_BOWSER_NPC_STAIRS, 1, 3, 30, 200, _("\
@FF0202FFstairs\n\
"))

DEFINE_DIALOG(DIALOG_BOWSER_NPC_PATCH_CHALLENGE, 1, 3, 30, 200, _("\
@FF0202FFu suck at patch challenge\n\
"))

DEFINE_DIALOG(DIALOG_BOWSER_SEWNIA_NPC_ANGER, 1, 3, 30, 200, _("\
@FF0202FFget mad\n\
"))

DEFINE_DIALOG(DIALOG_LEAVING_SECOND_HUB, 1, 3, 30, 200, _("\
@7F60B4FFIt's open...\n\
I hope we won't have to see him again...\n\
Well... Let's go.\n\
@7F60B4FFShould we do what we did last time?\n\
You run ahead and I'll trail behind?\n\
I think that wou-\n\
@FF0202FFHey.\n\
\n\
\n\
@FF0202FFI have been scouring this place...\n\
Every nook, every cranny.\n\
Peach's thread isn't here!\n\
@FF0202FFI was an idiot for thinking your\n\
loser plan would work out!\n\
Move aside!\n\
@FF0202FFWe're doing things MY way now.\n\
And there WON'T be any objections!\n\
\n\
@FF0202FFIt's Bowser time!"))

DEFINE_DIALOG(DIALOG_BOWSER_BEFORE_SECOND_FIGHT, 1, 3, 30, 200, _("\
@FF0202FFUrgh...\n\
How much garbage did that guy make?\n\
Wait...\n\
@FF0202FFIs that...?\n\
\n\
\n\
@FF0202FFIt is!\n\
\n\
\n\
@FF0202FFBwahaha! Hey Mario, check it out!\n\
Looks like I get to save Peach today!\n\
I've got her thread, right in-"))

DEFINE_DIALOG(DIALOG_PATCHMAKER_BEFORE_SECOND_FIGHT, 0b10, 3, 30, 200, _("\
@5D5D5DFFWhy?\n\
\n\
\n\
@5D5D5DFFWhy must you move!?\n\
Why must you interrupt my work!?\n\
Why? WhywhywhywhywhyWHY?\n\
@5D5D5DFFBe silent! Let me work!\n\
Hahahaha!!! Go away!\n\
I'm so close!\n\
@5D5D5DFFI am!\n\
You...\n\
Stop looking at me like that!\n\
@5D5D5DFFI am close!\n\
Don't look at me like that!\n\
I really really really am!\n\
@5D5D5DFFIf you won't stop moving...\n\
I have no choice but to pin you\n\
down forever!!!"))

DEFINE_DIALOG(DIALOG_PATCHMAKER_DEFEATED_SECOND_FIGHT, 0b10, 3, 30, 200, _("\
@5D5D5DFFWhy... why?\n\
\n\
\n\
@5D5D5DFFWhy can't I...\n\
Why won't it...\n\
Why...\n\
@5D5D5DFFWhy?"))

DEFINE_DIALOG(DIALOG_PATCHMAKER_LISTEN, 0b10, 3, 30, 200, _("\
@5D5D5DFFPlease...\n\
Listen...\n\
Closer..."))

DEFINE_DIALOG(DIALOG_PATCHMAKER_BREAKING_POINT, 0b10, 3, 30, 200, _("\
@7F60B4FFNo!!!\n\
\n\
\n\
@5D5D5DFF...?\n\
\n\
\n\
@5D5D5DFFY...\n\
\n\
\n\
@5D5D5DFFY... O... U!\n\
\n\
\n\
@5D5D5DFFIt's YOUR FAULT!\n\
YOU were the reason I became like this!\n\
WHY couldn't I RECREATE you!?\n\
@5D5D5DFFWHY did you have to ask for a sister!?\n\
HOW did you even come to be!?\n\
WHY COULDN'T YOU TELL ME???\n\
@5F4094FFYou're... you're hurting me!"))

DEFINE_DIALOG(DIALOG_SEWNIA_HEAD_RIPPED_OFF, 0b10, 3, 30, 200, _("\
@5F4094FFMario...\n\
\n\
\n\
@5F4094FFDon't... you see now?\n\
This is... why...\n\
\n\
@5F4094FFThis is why we have to...\n\
end... him..."))

DEFINE_DIALOG(DIALOG_RETURN_FROM_SUBAREA, 1, 4, 30, 200, _("\
@FEFEFEFFReturn to the main area? \n\
//Yes    //No      "))